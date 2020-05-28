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

var mas = [1.0, 2.0]
var res = [0.0, 0.0]
var array = new DoubleArray(mas);
var array_res = new DoubleArray(res);

console.log("Sphere func = ", my_lib.sphere_function(mas, mas.length))
console.log("Ekli func = ", my_lib.ekli_function(mas, mas.length))

my_lib.hooke_jeeves_method(array, mas.length, "Ekli_func", array_res, 0.001)
res_final = [array_res[0], array_res[1]]
console.log("Hooke Jeeves method: ", res_final, " , time = ", my_lib.get_execution_time())

my_lib.luus_jaakola_method(array, mas.length, "Ekli_func", array_res, 0.001)
res_final = [array_res[0], array_res[1]]
console.log("Luus Jaakola method: ", res_final, " , time = ", my_lib.get_execution_time())

my_lib.competing_points_method(array, mas.length, "Ekli_func", array_res)
res_final = [array_res[0], array_res[1]]
console.log("Competing points method: ", res_final, " , time = ", my_lib.get_execution_time())
