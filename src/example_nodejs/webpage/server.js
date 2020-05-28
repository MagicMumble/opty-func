const express = require('express'),
    server = express();
var ffi = require("ffi");
var ArrayType = require('ref-array');
var DoubleArray = ArrayType('double');

var user = process.env.USER || ""
lib = "/home/" + user + "/.local/share/opty-func/build/src/test_funcs_lib/libtest_funcs_optimize.so"

var my_lib = ffi.Library(lib, {
    "sphere_function": ['double', [DoubleArray, 'int']],
    "rastrigin_function": ['double', [DoubleArray, 'int']],
    "stibinki_tanga_function": ['double', [DoubleArray, 'int']],
    "ekli_function": ['double', [DoubleArray, 'int']],
    "rosenbrock_function": ['double', [DoubleArray, 'int']],
    "bill_function": ['double', [DoubleArray, 'int']],
    "goldman_price_function": ['double', [DoubleArray, 'int']],
    "boot_function": ['double', [DoubleArray, 'int']],
    "bookin_function": ['double', [DoubleArray, 'int']],
    "matias_function": ['double', [DoubleArray, 'int']],
    "levi_function": ['double', [DoubleArray, 'int']],
    "three_humped_camel_function": ['double', [DoubleArray, 'int']],
    "easom_function": ['double', [DoubleArray, 'int']],
    "luus_jaakola_method": ['void', [DoubleArray, 'int', 'string', DoubleArray, 'float']],
    "hooke_jeeves_method": ['void', [DoubleArray, 'int', 'string', DoubleArray, 'float']],
    "competing_points_method": ['void', [DoubleArray, 'int', 'string', DoubleArray]],
    "get_execution_time": ['double', []],
    "get_min_x_sphere_function": ['void', [DoubleArray, 'int']],
    "get_min_x_rastrigin_function": ['void', [DoubleArray, 'int']],
    "get_min_x_stibinski_tanga_function": ['void', [DoubleArray, 'int']],
    "get_min_x_ekli_function": ['void', [DoubleArray, 'int']],
    "get_min_x_rosenbrock_function": ['void', [DoubleArray, 'int']],
    "get_min_x_bill_function": ['void', [DoubleArray, 'int']],
    "get_min_x_goldman_price_function": ['void', [DoubleArray, 'int']],
    "get_min_x_boot_function": ['void', [DoubleArray, 'int']],
    "get_min_x_bookin_function": ['void', [DoubleArray, 'int']],
    "get_min_x_matias_function": ['void', [DoubleArray, 'int']],
    "get_min_x_levi_function": ['void', [DoubleArray, 'int']],
    "get_min_x_three_hump_camel_function": ['void', [DoubleArray, 'int']],
    "get_min_x_easom_function": ['void', [DoubleArray, 'int']],
});

var methods = [my_lib.hooke_jeeves_method, my_lib.luus_jaakola_method, my_lib.competing_points_method]
var funcs = ["Sphere_func", "Rastrigin_func", "Stibinski_Tang_func", "Ekli_func", "Rosenbrock_func", "Bill_func", "Goldman_Price_func",
     "Boot_func", "Bookin_func", "Matias_func", "Levi_func", "Three_hump_camel_func", "Easom_func"]
var functions = [my_lib.sphere_function, my_lib.rastrigin_function, my_lib.stibinki_tanga_function, my_lib.ekli_function, my_lib.rosenbrock_function,
    my_lib.bill_function, my_lib.goldman_price_function, my_lib.boot_function, my_lib.bookin_function, my_lib.matias_function, my_lib.levi_function,
    my_lib.three_humped_camel_function, my_lib.easom_function]
var meths_num = methods.length
var funcs_num = funcs.length
var x_mins = [my_lib.get_min_x_sphere_function, my_lib.get_min_x_rastrigin_function, my_lib.get_min_x_stibinski_tanga_function, my_lib.get_min_x_ekli_function,
    my_lib.get_min_x_rosenbrock_function, my_lib.get_min_x_bill_function, my_lib.get_min_x_goldman_price_function, my_lib.get_min_x_boot_function,
    my_lib.get_min_x_bookin_function, my_lib.get_min_x_matias_function, my_lib.get_min_x_levi_function, my_lib.get_min_x_three_hump_camel_function,
    my_lib.get_min_x_easom_function]

function get_exec_time(array, array_res, eps) {
    var data = [];
    var func_values = [];
    var f_mins = [];

    for ( var s = 0; s < x_mins.length; s ++ ) {
        x_mins[s](array_res, array_res.length)
        f_mins.push(functions[s](array_res, array_res.length))
    }

    for ( var i = 0; i < methods.length; i ++ ) {
        var time = [];
        var func_value = [];
        if (methods[i] === my_lib.competing_points_method) {
            for ( var j = 0; j < funcs.length; j ++ ) {
                methods[i](array, array.length, funcs[j], array_res)
                func_value.push(functions[j](array_res, array_res.length))
                time.push(1000*my_lib.get_execution_time());                 //в милисекундах
            }
        } else {
            for (var k = 0; k < funcs.length; k++) {
                methods[i](array, array.length, funcs[k], array_res, eps)
                func_value.push(functions[k](array_res, array_res.length))
                time.push(1000*my_lib.get_execution_time());
            }
        }
        func_values.push(func_value)
        data.push(time);
    }
    return [data, func_values, funcs, f_mins];
}

var bodyParser = require('body-parser')
server.set('port', process.env.PORT || 3000);
var urlencodedParser = bodyParser.urlencoded({ extended: false })

server.post("/", urlencodedParser, function(req, res) {
    console.log("GOT REQUEST = ", req.body);
    var eps = parseFloat(req.body.eps);
    var x0 = req.body.x0;
    var mas = x0.split(" ");
    var res_mas = [];
    for (var i=0; i<mas.length; i++) {
        mas[i] = parseFloat(mas[i])
        res_mas.push(0.0)
    }
    var array = new DoubleArray(mas);
    var array_res = new DoubleArray(res_mas);
    var data_exec_time = get_exec_time(array, array_res, eps);
    res.set('Access-Control-Allow-Origin', '*')
    res.set("Access-Control-Allow-Headers", "Content-Type");
    res.writeHead(200, {'Content-Type': 'text'});
    res.end(JSON.stringify(data_exec_time))
});

server.use((req, res)=>{
    res.type('text/plain');
    res.status(505);
    res.send('Error page');
});

server.listen(3000, ()=>{
    console.log('Express server started at port 3000');
});
