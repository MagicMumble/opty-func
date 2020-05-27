#include <stdio.h>
#include "test_funcs_optimize.h"

int main() {
    int n2 = 2;
    double x_start2[] = {3.0, 4.0};
    double mas_res[n2];
    
    hooke_jeeves_method(x_start2, n2, "Matias_func", mas_res, 0.001);
    double calculated_glob_min = sphere_function(mas_res, n2);
    get_min_x_sphere_function(mas_res, n2);
    double real_glob_min = sphere_function(mas_res, n2);
    double time = get_execution_time();
    
    printf("calc_min = %lf, real_min %lf, exec_time = %lf seconds\n", calculated_glob_min, real_glob_min, time);
    return 0;
}
