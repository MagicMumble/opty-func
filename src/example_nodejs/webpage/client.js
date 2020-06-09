document.getElementById("build_boxplot").addEventListener("click", send_request);

function send_request() {
    var eps = document.getElementById("eps").value;
    var x0 = document.getElementById("x0").value;
    jQuery.ajax({
            type: 'POST',
            url: 'http://127.0.0.1:3000/',
            dataType: "text",
            cache: false,
            data: {"eps": eps, "x0": x0},
            success: build_boxplot,
            error: function (jqXHR, textStatus, errorThrown) {
                alert('error ' + textStatus + " " + errorThrown);
            }
        }
    )
}

function build_boxplot(resp) {
    var plot1 = document.getElementById('plot1');
    var xData = ['Hooke<br>Jeeves<br>method', 'Luus<br>Jaakola<br>method',
        'Competing<br>points<br>method'];
    var res= jQuery.parseJSON(resp);
    var yData = res[0]
    var func_values = res[1]
    var func_names = res[2]
    var func_mins = res[3]
    var colors = ['rgba(93, 164, 214, 0.5)', 'rgba(255, 144, 14, 0.5)', 'rgba(44, 160, 101, 0.5)'];
    var data = [];

    for (var i = 0; i < xData.length; i++) {
        var result = {
            type: 'box',
            y: yData[i],
            name: xData[i],
            boxpoints: 'all',
            jitter: 0.5,
            whiskerwidth: 0.2,
            fillcolor: colors[i],
            width: 0.2,
            marker: {
                size: 3
            },
            line: {
                width: 2
            }
        };
        data.push(result);
    }

    layout = {
        title: 'Comparison of every method\'s execution time (in miliseconds)',
        yaxis: {
            autorange: true,
            showgrid: true,
            zeroline: true,
            dtick: 200,                                                 //расстояние между y по горизонтали
            gridcolor: 'rgb(255, 255, 255)',
            gridwidth: 1,
            zerolinecolor: 'rgb(255, 255, 255)',
            zerolinewidth: 2
        },
        paper_bgcolor: 'rgb(243,243,243)',
        plot_bgcolor: 'rgb(243, 243, 243)',
        showlegend: false,
        margin: {l: 40, r: 10, t: 80, b: 100},
    };

    Plotly.newPlot(plot1, data, layout);

    var plots = [document.getElementById('plot2'), document.getElementById('plot3'), document.getElementById('plot4')]
    var methods = ['Hooke Jeeves method', 'Luus Jaakola method', 'Competing points method']
    var d_tick = [2, 2, 150]
    for (i=0; i<methods.length; i++) {
        var trace = make_trace_layout_seperatly(yData[i], methods[i], d_tick[i])
        Plotly.newPlot(plots[i], trace[0], trace[1]);
    }
    console.log(func_values)
    make_table_values(func_values, xData, func_names, func_mins, yData)
}

function make_table_values(func_values, methods, func_names, func_mins, times) {
    var vals = []
    vals.push(func_names)                         //столбцы (без первой строки)
    for (var k=0; k<func_values.length; k++) {
        vals.push(func_values[k])
    }
    vals.push(func_mins)
    var meths = []                                   //первая строка
    meths.push(["<b></b>"])
    for (var i=0; i<methods.length; i++) {
        meths.push([methods[i]])
    }
    meths.push("Real<br>global<br>min")
    table(meths, vals, "<br>Comparison of found and real global minimums</br>", 'table1')

    var row = meths.slice(0, meths.length-1)
    var columns = []
    columns.push(func_names)
    for (k=0; k<func_values.length; k++) {
        var column = []
        for (i=0; i<func_values[k].length; i++) {
            column.push(Math.abs(func_values[k][i]-func_mins[i]))
        }
        columns.push(column)
    }
    table(row, columns, "<br>Error between found and real global minimums</br>", 'table2')

    var cols = []
    cols.push(func_names)
    for (k=0; k<func_values.length; k++) {
        var coln = []
        for (i=0; i<func_values[k].length; i++) {
            if (columns[k+1][i] < 0.1) {
                coln.push("+")
            } else {
                coln.push("-")
            }
        }
        cols.push(coln)
    }
    table(row, cols, "<br>Was the right solution found with precise of 0.1?</br>", 'table3')

    var temps = []
    temps.push(func_names)
    for (k=0; k<func_values.length; k++) {
        temps.push(times[k])
    }
    table(row, temps, "<br>Execution time (in miliseconds)</br>", 'table4')
}

function table(meths, vals, name, elem) {
    var data = [{
        type: 'table',
        header: {
            values: meths,                                         //первая строка! (заголовки)
            align: ["left", "center"],
            line: {width: 1, color: '#506784'},
            fill: {color: '#c5deea'},
            font: {family: "Arial", size: 16, color: "black"},
            height: 30
        },
        cells: {
            values: vals,
            align: ["left", "center"],
            line: {color: "#506784", width: 1},
            fill: {color: ['#cce0e0', 'white']},
            font: {family: "Arial", size: 16, color: ["#132031"]},
            height: 30
        }
    }]
    var layout = {
        title: name
    }
    Plotly.newPlot(elem, data, layout);
}

function  make_trace_layout_seperatly(y, method, n) {
    var trace = {
        y: y,
        type: 'box',
        name: method,
        jitter: 0.3,
        marker: {
            color: 'rgb(7,40,89)'
        },
        boxpoints: 'all'
    };

    layout = {
        title: method + ' execution time (in miliseconds)',
        yaxis: {
            autorange: true,
            showgrid: true,
            zeroline: true,
            dtick: n,                                                 //расстояние между y по горизонтали
            gridcolor: 'rgb(255, 255, 255)',
            gridwidth: 1,
            zerolinecolor: 'rgb(255, 255, 255)',
            zerolinewidth: 2
        },
        paper_bgcolor: 'rgb(243,243,243)',
        plot_bgcolor: 'rgb(243, 243, 243)',
        showlegend: false,
        margin: {l: 40, r: 10, t: 80, b: 100},
    };
    return [[trace] , layout]
}
