package binding

//#include <stdlib.h>
// #cgo LDFLAGS: -L${SRCDIR}/../../../build/src/test_funcs_lib -ltest_funcs_optimize
// #cgo CFLAGS: -I${SRCDIR}/../../../src/test_funcs_lib/
// #include "test_funcs_optimize.h"
import "C"

func convert_to_c_array(m []float64) []C.double {
	mas := make([]C.double, len(m))
	for i:=0; i<len(m); i++ {
		mas[i] = C.double(m[i])
	}
	return mas
}

func Sphere_function(m []float64) float64{
	return float64(C.sphere_function(&convert_to_c_array(m)[0], C.int(len(m))))
}

func Rastrigin_function(m []float64) float64{
	return float64(C.rastrigin_function(&convert_to_c_array(m)[0], C.int(len(m))))
}

func Stibinski_Tanga_function(m []float64) float64{
	return float64(C.stibinki_tanga_function(&convert_to_c_array(m)[0], C.int(len(m))))
}

func Ekli_function(m []float64) float64{
	return float64(C.ekli_function(&convert_to_c_array(m)[0], C.int(len(m))))
}

func Rosenbrock_function(m []float64) float64{
	return float64(C.rosenbrock_function(&convert_to_c_array(m)[0], C.int(len(m))))
}

func Bill_function(m []float64) float64{
	return float64(C.bill_function(&convert_to_c_array(m)[0], C.int(len(m))))
}

func Goldman_price_function(m []float64) float64{
	return float64(C.goldman_price_function(&convert_to_c_array(m)[0], C.int(len(m))))
}

func Boot_function(m []float64) float64{
	return float64(C.boot_function(&convert_to_c_array(m)[0], C.int(len(m))))
}

func Bookin_function(m []float64) float64{
	return float64(C.bookin_function(&convert_to_c_array(m)[0], C.int(len(m))))
}

func Matias_function(m []float64) float64{
	return float64(C.matias_function(&convert_to_c_array(m)[0], C.int(len(m))))
}

func Levi_function(m []float64) float64{
	return float64(C.levi_function(&convert_to_c_array(m)[0], C.int(len(m))))
}

func Three_hump_camel_function(m []float64) float64{
	return float64(C.three_humped_camel_function(&convert_to_c_array(m)[0], C.int(len(m))))
}

func Easom_function(m []float64) float64{
	return float64(C.easom_function(&convert_to_c_array(m)[0], C.int(len(m))))
}

func Luus_jaakola_method(m []float64, s string, eps float32) []C.double {
	res := make([]C.double, len(m))
	C.luus_jaakola_method(&convert_to_c_array(m)[0], C.int(len(m)), C.CString(s), &res[0], C.float(eps))
	return res
}

func Competing_points_method(m []float64, s string) []C.double {
	res := make([]C.double, len(m))
	C.competing_points_method(&convert_to_c_array(m)[0], C.int(len(m)), C.CString(s), &res[0])
	return res
}

func Hooke_jeeves_method(m []float64, s string, eps float32) []C.double {
	res := make([]C.double, len(m))
	C.hooke_jeeves_method(&convert_to_c_array(m)[0], C.int(len(m)), C.CString(s), &res[0], C.float(eps))
	return res
}

func Get_execution_time() float64{
	return float64(C.get_execution_time())
}

func Get_min_x_rastrigin_function(m []float64) []C.double {
	res := convert_to_c_array(m)
	C.get_min_x_rastrigin_function(&res[0], C.int(len(m)))
	return res
}

func Get_min_x_stibinski_tanga_function(m []float64) []C.double {
	res := convert_to_c_array(m)
	C.get_min_x_stibinski_tanga_function(&res[0], C.int(len(m)))
	return res
}

func Get_min_x_ekli_function(m []float64) []C.double {
	res := convert_to_c_array(m)
	C.get_min_x_ekli_function(&res[0], C.int(len(m)))
	return res
}

func Get_min_x_sphere_function(m []float64) []C.double {
	res := convert_to_c_array(m)
	C.get_min_x_sphere_function(&res[0], C.int(len(m)))
	return res
}

func Get_min_x_rosenbrock_function(m []float64) []C.double {
	res := convert_to_c_array(m)
	C.get_min_x_rosenbrock_function(&res[0], C.int(len(m)))
	return res
}

func Get_min_x_bill_function(m []float64) []C.double {
	res := convert_to_c_array(m)
	C.get_min_x_bill_function(&res[0], C.int(len(m)))
	return res
}

func Get_min_x_goldman_price_function(m []float64) []C.double {
	res := convert_to_c_array(m)
	C.get_min_x_goldman_price_function(&res[0], C.int(len(m)))
	return res
}

func Get_min_x_bookin_function(m []float64) []C.double {
	res := convert_to_c_array(m)
	C.get_min_x_bookin_function(&res[0], C.int(len(m)))
	return res
}

func Get_min_x_boot_function(m []float64) []C.double {
	res := convert_to_c_array(m)
	C.get_min_x_boot_function(&res[0], C.int(len(m)))
	return res
}

func Get_min_x_matias_function(m []float64) []C.double {
	res := convert_to_c_array(m)
	C.get_min_x_matias_function(&res[0], C.int(len(m)))
	return res
}

func Get_min_x_levi_function(m []float64) []C.double {
	res := convert_to_c_array(m)
	C.get_min_x_levi_function(&res[0], C.int(len(m)))
	return res
}

func Get_min_x_three_hump_camel_function(m []float64) []C.double {
	res := convert_to_c_array(m)
	C.get_min_x_three_hump_camel_function(&res[0], C.int(len(m)))
	return res
}

func Get_min_x_easom_function(m []float64) []C.double {
	res := convert_to_c_array(m)
	C.get_min_x_easom_function(&res[0], C.int(len(m)))
	return res
}

