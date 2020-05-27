#ifndef DIPLOM1_INTERFACE_H
#define DIPLOM1_INTERFACE_H

void get_min_x_rastrigin_function(double*, int);
void get_min_x_stibinski_tanga_function(double*, int);
void get_min_x_ekli_function(double*, int);
void get_min_x_sphere_function(double*, int);
void get_min_x_rosenbrock_function(double*, int);
void get_min_x_bill_function(double*, int);
void get_min_x_goldman_price_function(double*, int);
void get_min_x_bookin_function(double*, int);
void get_min_x_boot_function(double*, int);
void get_min_x_matias_function(double*, int);
void get_min_x_levi_function(double*, int);
void get_min_x_three_hump_camel_function(double*, int);
void get_min_x_easom_function(double*, int);

double get_execution_time();
double (*define_function_name(char*)) (double*, int);
double norm(double*, int);

double rastrigin_function(double*, int);
double stibinki_tanga_function(double*, int);
double ekli_function(double*, int);
double sphere_function(double*, int);
double rosenbrock_function(double*, int);
double bill_function(double*, int);
double goldman_price_function(double*, int);
double boot_function(double*, int);
double bookin_function(double*, int);
double matias_function(double*, int);
double levi_function(double*, int);
double three_humped_camel_function(double*, int);
double easom_function(double*, int);

void hooke_jeeves_method(const double*, int, char*, double*, float);
void luus_jaakola_method(const double*, int, char*, double*, float);
void competing_points_method(const double*, int, char*, double*);

#endif //DIPLOM1_INTERFACE_H
