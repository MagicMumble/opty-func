#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "test_funcs_optimize.h"
#include "unity.h"

typedef void (*min_x)(double*, int);
typedef double (*function)(double*, int);
typedef void (*method)(const double*, int, char*, double*, float);

char* func_names[] = {"Sphere_func", "Rastrigin_func", "Stibinski_Tang_func", "Ekli_func", "Rosenbrock_func", "Bill_func",
                      "Goldman_Price_func", "Boot_func", "Bookin_func", "Matias_func", "Levi_func", "Three_hump_camel_func", "Easom_func"};

min_x get_min_x[] = {get_min_x_sphere_function, get_min_x_rastrigin_function, get_min_x_stibinski_tanga_function,
                     get_min_x_ekli_function, get_min_x_rosenbrock_function, get_min_x_bill_function, get_min_x_goldman_price_function,
                     get_min_x_boot_function, get_min_x_bookin_function, get_min_x_matias_function, get_min_x_levi_function,
                     get_min_x_three_hump_camel_function, get_min_x_easom_function};

function funcs[] = {sphere_function, rastrigin_function, stibinki_tanga_function, ekli_function, rosenbrock_function, bill_function,
                    goldman_price_function, boot_function, bookin_function, matias_function, levi_function, three_humped_camel_function, easom_function};

method methods[] = {hooke_jeeves_method, luus_jaakola_method, (method) competing_points_method};

char cur_func_name[50];
min_x cur_min_x;
function cur_func;
method cur_method;
double cur_err;

int n3 = 3;
int n2 = 2;
float eps = 0.1;
double x_start3[] = {10.0, 11.0, 13.0};
double x_start2[] = {3.0, 4.0};
double mas_res2[2];
double mas_res3[3];
double real_min[2];

void setUp (void) {                        // Is run before every test
    if (*cur_method == *methods[0]) {
        printf("\nTesting %s with hooke jeeves method\n", cur_func_name);
    } else if (*cur_method == *methods[1]) {
        printf("\nTesting %s with luus jaakola method\n", cur_func_name);
    } else {
        printf("\nTesting %s with competing points method\n", cur_func_name);
    }
}

void tearDown (void) {                      // Is run after every test
    printf("\n\033[1;32mCalculated min: %lf, real min: %lf,\n exec_time: %lf seconds, error: %lf\n\033[0m", cur_func(mas_res2, n2),  //green color
           cur_func(real_min, n2), get_execution_time(), cur_err);
}

void test_method() {
    (*cur_method)(x_start2, n2, cur_func_name, mas_res2, eps);
    cur_min_x(real_min, n2);
    cur_err = fabs(cur_func(mas_res2, n2) - cur_func(real_min, n2));
    TEST_ASSERT_EQUAL_INT(0, cur_err > eps);
}

int main() {
    int len_funcs = 13;
    int len_methods = 3;

    UNITY_BEGIN();
    for(int k=0; k<len_methods; k++) {
        cur_method = methods[k];
        for (int i = 0; i < len_funcs; i++) {
            strcpy(cur_func_name, func_names[i]);
            cur_min_x = get_min_x[i];
            cur_func = funcs[i];
            if (TEST_PROTECT()) {
                RUN_TEST(test_method);
            }
        }
    }
    return UNITY_END();
}
