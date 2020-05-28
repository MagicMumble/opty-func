package main
import (
	"binding"
	"fmt"
)

func main() {
	mas := []float64{3.0, 3.0}
	fmt.Println(binding.Sphere_function(mas))
	fmt.Println(binding.Rastrigin_function(mas))
	fmt.Println(binding.Stibinski_Tanga_function(mas))
	fmt.Println(binding.Ekli_function(mas))
	fmt.Println(binding.Rosenbrock_function(mas))
	fmt.Println(binding.Bill_function(mas))
	fmt.Println(binding.Goldman_price_function(mas))
	fmt.Println(binding.Boot_function(mas))
	fmt.Println(binding.Bookin_function(mas))
	fmt.Println(binding.Matias_function(mas))
	fmt.Println(binding.Levi_function(mas))
	fmt.Println(binding.Three_hump_camel_function(mas))
	fmt.Println(binding.Easom_function(mas))

	fmt.Println(binding.Luus_jaakola_method(mas, "Sphere_func", 0.001))    
	fmt.Println(binding.Hooke_jeeves_method(mas, "Sphere_func", 0.001))
	fmt.Println(binding.Competing_points_method(mas, "Sphere_func"))

	fmt.Println("EXEC TIME =", binding.Get_execution_time())
	fmt.Println(binding.Get_min_x_rastrigin_function(mas))
	fmt.Println(binding.Get_min_x_stibinski_tanga_function(mas))
	fmt.Println(binding.Get_min_x_ekli_function(mas))
	fmt.Println(binding.Get_min_x_sphere_function(mas))
	fmt.Println(binding.Get_min_x_rosenbrock_function(mas))
	fmt.Println(binding.Get_min_x_bill_function(mas))
	fmt.Println(binding.Get_min_x_goldman_price_function(mas))
	fmt.Println(binding.Get_min_x_bookin_function(mas))
	fmt.Println(binding.Get_min_x_boot_function(mas))
	fmt.Println(binding.Get_min_x_matias_function(mas))
	fmt.Println(binding.Get_min_x_levi_function(mas))
	fmt.Println(binding.Get_min_x_three_hump_camel_function(mas))
	fmt.Println(binding.Get_min_x_easom_function(mas))

}
