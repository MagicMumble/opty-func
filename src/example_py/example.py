import binding

my_list = [9, 2, 3]

print("Hooke_Jeeves_method for sphere func: ", binding.hooke_jeeves_method(my_list, "Sphere_func", 0.001))
print("Luus_Jaakola_method for sphere func: ", binding.luus_jaakola_method(my_list, "Sphere_func", 0.001))
print("Competing_points_method for sphere func: ", binding.competing_points_method(my_list, "Sphere_func"))
print("time of compet_points_meth for sphere_func: ", binding.get_execution_time())

x = [3, 4]
print("Rastrigin: ", binding.rastrigin_function(x))
print("Stibinski_Tanga: ", binding.stibinski_tanga_function(x))
print("Ekli: ", binding.ekli_function(x))
print("Sphere: ", binding.sphere_function(x))
print("Rosenbrock: ", binding.rosenbrock_function(x))
print("Bill: ", binding.bill_function(x))
print("Goldman_Price: ", binding.goldman_price_function(x))
print("Boot: ", binding.boot_function(x))
print("Bookin: ", binding.bookin_function(x))
print("Matias: ", binding.matias_function(x))
print("Levi: ", binding.levi_function(x))
print("Three_hump_camel: ", binding.three_humped_camel_function(x))
print("Easom: ", binding.easom_function(x))

res = [100.0, 1100.0]
print("rastrigin_min_x: ", binding.get_min_x_rastrigin_function(res))
print("bill_min_x: ", binding.get_min_x_bill_function(res))
print("boot_min_x: ", binding.get_min_x_boot_function(res))
print("bookin_min_x: ", binding.get_min_x_bookin_function(res))
print("three_hump_camel_min_x: ", binding.get_min_x_three_hump_camel_function(res))
print("easom_min_x: ", binding.get_min_x_easom_function(res))
print("ekli_min_x: ", binding.get_min_x_ekli_function(res))
print("goldman_price_min_x: ", binding.get_min_x_goldman_price_function(res))
print("levi_min_x: ", binding.get_min_x_levi_function(res))
print("matias_min_x: ", binding.get_min_x_matias_function(res))
print("rosenbrock_min_x: ", binding.get_min_x_rosenbrock_function(res))
print("stibinski_tanga_min_x: ", binding.get_min_x_stibinski_tanga_function(res))
print("sphere_min_x: ", binding.get_min_x_sphere_function(res))



