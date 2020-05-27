import ctypes

def prepare_data_for_method(list_in, str, method, eps):
    n = len(list_in)
    s = (ctypes.c_char * len(str))()
    s[:] = [s.encode('utf-8') for s in str]
    c_arr_in = (ctypes.c_double * n)(*list_in)
    c_arr_out = (ctypes.c_double * n)()
    method.restype = None
    method(c_arr_in, ctypes.c_int(n), s, c_arr_out, ctypes.c_float(eps))
    return c_arr_out[:]

def hooke_jeeves_method(list_in, str, eps):
    return prepare_data_for_method(list_in, str, py_hooke_jeeves_method, eps)

def luus_jaakola_method(list_in, str, eps):
    return prepare_data_for_method(list_in, str, py_luus_jaakola_method, eps)

def competing_points_method(list_in, str):
    return prepare_data_for_method(list_in, str, py_competing_points_method, 0)


def prepare_data_for_function(list_in, func):
    func.restype = ctypes.c_double
    return func((ctypes.c_double * len(list_in))(*list_in), ctypes.c_int(len(list_in)))

def rastrigin_function(list_in):
    return prepare_data_for_function(list_in, py_rastrigin_function)

def stibinski_tanga_function(list_in):
    return prepare_data_for_function(list_in, py_stibinski_tanga_function)

def ekli_function(list_in):
    return prepare_data_for_function(list_in, py_ekli_function)

def sphere_function(list_in):
    return prepare_data_for_function(list_in, py_sphere_function)

def rosenbrock_function(list_in):
    return prepare_data_for_function(list_in, py_rosenbrock_function)

def bill_function(list_in):
    return prepare_data_for_function(list_in, py_bill_function)

def goldman_price_function(list_in):
    return prepare_data_for_function(list_in, py_goldman_price_function)

def boot_function(list_in):
    return prepare_data_for_function(list_in, py_boot_function)

def bookin_function(list_in):
    return prepare_data_for_function(list_in, py_bookin_function)

def matias_function(list_in):
    return prepare_data_for_function(list_in, py_matias_function)

def levi_function(list_in):
    return prepare_data_for_function(list_in, py_levi_function)

def three_humped_camel_function(list_in):
    return prepare_data_for_function(list_in, py_three_humped_camel_function)

def easom_function(list_in):
    return prepare_data_for_function(list_in, py_easom_function)

def get_execution_time():
    py_get_execution_time.restype = ctypes.c_double
    return py_get_execution_time()


def prepare_data_for_min_x(res_in, func):
    func.restype = None
    c_arr = (ctypes.c_double * len(res_in))(*res_in)
    func(c_arr, ctypes.c_int(len(res_in)))
    return c_arr[:]

def get_min_x_rastrigin_function(res_in):
    return prepare_data_for_min_x(res_in, py_get_min_x_rastrigin_function)

def get_min_x_ekli_function(res_in):
    return prepare_data_for_min_x(res_in, py_get_min_x_ekli_function)

def get_min_x_stibinski_tanga_function(res_in):
    return prepare_data_for_min_x(res_in, py_get_min_x_stibinski_tanga_function)

def get_min_x_sphere_function(res_in):
    return prepare_data_for_min_x(res_in, py_get_min_x_sphere_function)

def get_min_x_rosenbrock_function(res_in):
    return prepare_data_for_min_x(res_in, py_get_min_x_rosenbrock_function)

def get_min_x_bill_function(res_in):
    return prepare_data_for_min_x(res_in, py_get_min_x_bill_function)

def get_min_x_goldman_price_function(res_in):
    return prepare_data_for_min_x(res_in, py_get_min_x_goldman_price_function)

def get_min_x_bookin_function(res_in):
    return prepare_data_for_min_x(res_in, py_get_min_x_bookin_function)

def get_min_x_boot_function(res_in):
    return prepare_data_for_min_x(res_in, py_get_min_x_boot_function)

def get_min_x_matias_function(res_in):
    return prepare_data_for_min_x(res_in, py_get_min_x_matias_function)

def get_min_x_levi_function(res_in):
    return prepare_data_for_min_x(res_in, py_get_min_x_levi_function)

def get_min_x_three_hump_camel_function(res_in):
    return prepare_data_for_min_x(res_in, py_get_min_x_three_hump_camel_function)

def get_min_x_easom_function(res_in):
    return prepare_data_for_min_x(res_in, py_get_min_x_easom_function)

lib_path = '../build/src/test_funcs_lib/libtest_funcs_optimize.so'
try:
    basic_function_lib = ctypes.CDLL(lib_path)         
    py_hooke_jeeves_method = basic_function_lib.hooke_jeeves_method
    py_luus_jaakola_method = basic_function_lib.luus_jaakola_method
    py_competing_points_method = basic_function_lib.competing_points_method

    py_rastrigin_function = basic_function_lib.rastrigin_function
    py_stibinski_tanga_function = basic_function_lib.stibinki_tanga_function
    py_ekli_function = basic_function_lib.ekli_function
    py_sphere_function = basic_function_lib.sphere_function
    py_rosenbrock_function = basic_function_lib.rosenbrock_function
    py_bill_function = basic_function_lib.bill_function
    py_goldman_price_function = basic_function_lib.goldman_price_function
    py_boot_function = basic_function_lib.boot_function
    py_bookin_function = basic_function_lib.bookin_function
    py_matias_function = basic_function_lib.matias_function
    py_levi_function = basic_function_lib.levi_function
    py_three_humped_camel_function = basic_function_lib.three_humped_camel_function
    py_easom_function = basic_function_lib.easom_function

    py_get_execution_time = basic_function_lib.get_execution_time

    py_get_min_x_rastrigin_function = basic_function_lib.get_min_x_rastrigin_function
    py_get_min_x_stibinski_tanga_function = basic_function_lib.get_min_x_stibinski_tanga_function
    py_get_min_x_ekli_function = basic_function_lib.get_min_x_ekli_function
    py_get_min_x_sphere_function = basic_function_lib.get_min_x_sphere_function
    py_get_min_x_rosenbrock_function = basic_function_lib.get_min_x_rosenbrock_function
    py_get_min_x_bill_function = basic_function_lib.get_min_x_bill_function
    py_get_min_x_goldman_price_function = basic_function_lib.get_min_x_goldman_price_function
    py_get_min_x_bookin_function = basic_function_lib.get_min_x_bookin_function
    py_get_min_x_boot_function = basic_function_lib.get_min_x_boot_function
    py_get_min_x_matias_function = basic_function_lib.get_min_x_matias_function
    py_get_min_x_levi_function = basic_function_lib.get_min_x_levi_function
    py_get_min_x_three_hump_camel_function = basic_function_lib.get_min_x_three_hump_camel_function
    py_get_min_x_easom_function = basic_function_lib.get_min_x_easom_function
except:
    print('library not found')




