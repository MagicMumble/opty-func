#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "test_funcs_optimize.h"

double execution_time;

double get_execution_time() {
	return execution_time;
}

void error(int n) {
    printf("\033[1;31mVector size is invalid: given n = %d, required n = 2. Try again!\n\033[0m", n);   // red color
    exit(1);
}

void get_min_x_rastrigin_function(double* res, int n) {
    for (int i = 0; i < n; i++) {
        res[i] = 0.0;
    }
}

void get_min_x_stibinski_tanga_function(double* res, int n) {
    for (int i = 0; i < n; i++) {
        res[i] = -2.903534;
    }
}

void get_min_x_ekli_function(double* res, int n) {
    if (n != 2) {
        error(n);
    }
    for (int i = 0; i < n; i++) {
        res[i] = 0.0;
    }
}

void get_min_x_sphere_function(double* res, int n) {
    for (int i = 0; i < n; i++) {
        res[i] = 0.0;
    }
}

void get_min_x_rosenbrock_function(double* res, int n) {
    for (int i = 0; i < n; i++) {
        res[i] = 1.0;
    }
}

void get_min_x_bill_function(double* res, int n) {
    if (n != 2) {
        error(n);
    }
    res[0] = 3.0;
    res[1] = 0.5;
}

void get_min_x_goldman_price_function(double* res, int n) {
    if (n != 2) {
        error(n);
    }
    res[0] = 0.0;
    res[1] = -1.0;
}

void get_min_x_bookin_function(double* res, int n) {
    if (n != 2) {
        error(n);
    }
    res[0] = -10.0;
    res[1] = 1.0;
}

void get_min_x_boot_function(double* res, int n) {
    if (n != 2) {
        error(n);
    }
    res[0] = 1.0;
    res[1] = 3.0;
}

void get_min_x_matias_function(double* res, int n) {
    if (n != 2) {
        error(n);
    }
    res[0] = 0.0;
    res[1] = 0.5;
}

void get_min_x_levi_function(double* res, int n) {
    if (n != 2) {
        error(n);
    }
    res[0] = 1.0;
    res[1] = 1.0;
}

void get_min_x_three_hump_camel_function(double* res, int n) {
    if (n != 2) {
        error(n);
    }
    res[0] = 0.0;
    res[1] = 0.0;
}

void get_min_x_easom_function(double* res, int n) {
    if (n != 2) {
        error(n);
    }
    res[0] = 3.14;
    res[1] = 3.14;
}

double rastrigin_function(double *x, int n) {  // -5.12 <= x[i] <= 5.12       "Rastrigin_func"
    int i = 0, A = 10;
    double result = 0.0;
    for (i=0; i<n; i++) {
        result += pow(x[i], 2) - A*cos(2*M_PI*x[i]);
    }
    return result + A*i;
}

double stibinki_tanga_function(double* x, int n) {       // -5 <= x[i] <= 5     "Stibinski_Tang_func"
    int i = 0;
    double result = 0.0;
    for (i=0; i<n; i++) {
        result += pow(x[i], 4) - 16*pow(x[i], 2) + 5*x[i];
    }
    return result/2.0;
}

double ekli_function(double* x, int n) {     // -5 <= x[0], x[1] <= 5              "Ekli_func"
    if (n != 2) {
        error(n);
    }
    return -20.0 * pow(M_E, (-0.2 * sqrt(0.5 * (pow(x[0], 2) + pow(x[1], 2))))) -
           pow(M_E, 0.5 * (cos(2 * M_PI * x[0]) + cos(2 * M_PI * x[1]))) + M_E + 20.0;
}

double sphere_function(double* x, int n) {         // -oo <= x[i] <= oo           "Sphere_func"
    int i = 0;
    double result = 0.0;
    for (i=0; i<n; i++) {
        result += pow(x[i], 2);
    }
    return result;
}

double rosenbrock_function(double* x, int n) {                                   // "Rosenbrock_func"
    int i = 0;
    double result = 0.0;
    for (i=0; i<n-1; i++) {
        result += 100 * pow(x[i+1] - pow(x[i], 2), 2) + pow(x[i] - 1, 2);
    }
    return result;
}

double bill_function(double* x, int n) {     // -4.5 <= x[0], x[1] <= 4.5         "Bill_func"
    if (n != 2) {
        error(n);
    }
    return pow(1.5 - x[0] + x[0]*x[1], 2) + pow(2.25 - x[0] + x[0]*pow(x[1], 2), 2) + pow(2.625 - x[0] + x[0]*pow(x[1], 3), 2);
}

double goldman_price_function(double* x, int n) {       //-2 <= x[0], x[1] <= 2     "Goldman_Price_func"
    if (n != 2) {
        error(n);
    }
    return (1+pow(x[0]+x[1]+1, 2)*(19-14*x[0]+3*pow(x[0],2) - 14*x[1] + 6*x[0]*x[1] + 3*pow(x[1], 2)))*
           (30 + pow(2*x[0] - 3*x[1],2)*(18-32*x[0] + 12*pow(x[0],2) + 48*x[1] - 36*x[0]*x[1] + 27*pow(x[1], 2)));
}

double boot_function(double* x, int n) {     // -10.0 <= x[0], x[1] <= 10.0          "Boot_func"
    if (n != 2) {
        error(n);
    }
    return pow(x[0] + 2*x[1] - 7, 2) + pow(2*x[0] + x[1] - 5, 2);
}

double bookin_function(double* x, int n) {    // -15.0 <= x[0] <= -5, // -3 <= x[1] <= 3       "Bookin_func"
    if (n != 2) {
        error(n);
    }
    return 100*sqrt(fabs(x[1] - 0.01*pow(x[0], 2))) + 0.01*fabs(x[0] + 10);
}

double matias_function(double* x, int n) {     // -10.0 <= x[0], x[1] <= 10.0                  "Matias_func"
    if (n != 2) {
        error(n);
    }
    return 0.26*(pow(x[0], 2) + pow(x[1], 2)) - 0.48*x[0]*x[1];
}

double levi_function(double* x, int n) {       // -10.0 <= x[0], x[1] <= 10.0                 "Levi_func"
    if (n != 2) {
        error(n);
    }
    return pow(sin(3*M_PI*x[0]), 2) + pow(x[0]-1, 2)*(1 + pow(sin(3*M_PI*x[1]), 2)) + pow(x[1]-1, 2)*(1+pow(sin(2*M_PI*x[1]), 2));
}

double three_humped_camel_function(double* x, int n) {     // -5.0 <= x[0], x[1] <= 5.0         "Three_hump_camel_func"
    if (n != 2) {
        error(n);
    }
    return 2*pow(x[0], 2) - 1.05 * pow(x[0], 4) + pow(x[0], 6)/6.0 + x[0]*x[1] + pow(x[1], 2);
}

double easom_function(double* x, int n) {                    // -100.0 <= x[0], x[1] <= 100.0           "Easom_func"
    if (n != 2) {
        error(n);
    }
    return -cos(x[0])*cos(x[1])*pow(M_E, -(pow(x[0]-M_PI, 2) + pow(x[1]-M_PI, 2)));
}

double (*define_function_name(char* s)) (double*, int) {
    if (!strcmp("Rastrigin_func", s)) {
        return &rastrigin_function;
    } else if (!strcmp("Stibinski_Tang_func", s)) {
        return &stibinki_tanga_function;
    } else if (!strcmp("Ekli_func", s)) {
        return &ekli_function;
    } else if (!strcmp("Sphere_func", s)) {
        return &sphere_function;
    } else if (!strcmp("Rosenbrock_func", s)) {
        return &rosenbrock_function;
    } else if (!strcmp("Bill_func", s)) {
        return &bill_function;
    } else if (!strcmp("Goldman_Price_func", s)) {
        return &goldman_price_function;
    } else if (!strcmp("Boot_func", s)) {
        return &boot_function;
    } else if (!strcmp("Bookin_func", s)) {
        return &bookin_function;
    } else if (!strcmp("Matias_func", s)) {
        return &matias_function;
    } else if (!strcmp("Levi_func", s)) {
        return &levi_function;
    } else if (!strcmp("Three_hump_camel_func", s)) {
        return &three_humped_camel_function;
    } else if (!strcmp("Easom_func", s)) {
        return &easom_function;
    } else {
        printf("\033[1;31mUndefined function name \"%s\". Please try another function.\n\033[0m", s);
        exit(1);
    }
}

double norm(double* x, int n) {
    int i;
    double sum = 0.0;
    for (i = 0; i<n; i++) {
        sum += pow(x[i], 2);
    }
    return sqrt(sum);
}

double* put(const double* x, int n, int k, double val, double* x_copy) {
    int i;
    for (i=0; i<n; i++) {
        if (i == k) {
            x_copy[i] = val;
        } else {
            x_copy[i] = x[i];
        }
    }
    return x_copy;
}

double* svenn(const double* x_start, int n, int num, double (*function)(double*, int)) {
    double x0[n], x_copy[n];
    int k, i = 0;
    for (i=0; i<n; i++) {
        x0[i] = x_start[i];
    }
    static double ab[2] = {};
    double x_next, delta;
    double t = 0.5;
    if (function(put(x0, n, num, x0[num]-t, x_copy), n) >= function(x0, n)) {
        if (function(x0, n) <= function(put(x0, n, num, x0[num]+t, x_copy), n)) {
            ab[0] = x0[num] - t;
            ab[1] = x0[num] + t;
            return ab;
        } else {
            delta = t;
            ab[0] = x0[num];
            x_next = x0[num] + t;
            k = 1;
        }
    } else {
        if (function(x0, n) <= function(put(x0, n, num, x0[num]+t, x_copy), n)) {
            delta = -t;
            ab[1] = x0[num];
            x_next = x0[num] - t;
            k = 1;
        } else {
            return ab;                   //no unimodality here
        }
    }
    while (1) {
        x0[num] = x_next;
        x_next = x0[num] + pow(2, k)*delta;
        if (function(put(x0, n, num, x_next, x_copy), n) < function(x0, n)) {
            if (delta == t) {
                ab[0] = x0[num];
            } else {
                ab[1] = x0[num];
            }
            k ++;
        } else {
            break;
        }
    }
    if (delta == t) {
        ab[1] = x_next;
    } else {
        ab[0] = x_next;
    }
    return ab;
}

double bisection_method(double* xstart, int n, int num, double (*function)(double*, int), float eps) {
    double* ab = svenn(xstart, n, num, function);
    double x_start = ab[0];
    double x_end = ab[1];
    double x_middle = (x_start+x_end)/2;
    double x_copy[n];

    while (1) {
        double length = x_end - x_start;
        double x_left_middle = x_start + length / 4.0;
        double x_right_middle = x_end - length / 4.0;
        if (function(put(xstart, n, num, x_left_middle, x_copy), n) < function(put(xstart, n, num, x_middle, x_copy), n)) {
            x_end = x_middle;
            x_middle = x_left_middle;
        } else if (function(put(xstart, n, num, x_right_middle, x_copy), n) < function(put(xstart, n, num, x_middle, x_copy), n)) {
            x_start = x_middle;
            x_middle = x_right_middle;
        } else {
            x_start = x_left_middle;
            x_end = x_right_middle;
        }
        if (x_end - x_start <= eps) {
            break;
        }
    }
    return x_middle;
}

void minimize(double* x, int n, int num, double (*function)(double*, int), double (*method_opt)(double*, int, int, double (*)(double*, int), float), float eps) {
    int i;
    for (i=0; i<n; i++) {
        x[num] = method_opt(x, n, num, function, eps);
    }
}

void hooke_jeeves_method(const double* x_first, int n, char* s, double* res, float eps) {
    clock_t t = clock();
    double (*function)(double*, int) = define_function_name(s);
    double x_before[n];
    double new_x[n];
    int i;
    for (i = 0; i<n; i++) {
        new_x[i] = x_first[i];
        x_before[i] = x_first[i];
    }
    double new_f, f_before;
    while (1) {
        f_before = (*function)(new_x, n);
        for (i = 0; i < n; i++) {                                       //для каждой оси (каждой координаты) минимизируем
            minimize(new_x, n, i, (*function), bisection_method, eps);
        }
        new_f = (*function)(new_x, n);
        if (new_f < f_before) {   //если исследующий поиск был удачным
            for (i = 0; i < n; i++) {
                double tmp = x_before[i];
                x_before[i] = new_x[i];
                new_x[i] = new_x[i] + new_x[i] - tmp;
            }
        }
        for (i = 0; i < n; i++) {
            minimize(new_x, n, i, (*function), bisection_method, eps);
        }
        double error[n];
        for (i = 0; i < n; i++) {
            error[i] = x_before[i] - new_x[i];
        }
        if (norm(error, n) <= eps) {
            for (i = 0; i < n; i++) {
                res[i] = x_before[i];
            }
            t = clock() - t;
            execution_time = ((double)t)/CLOCKS_PER_SEC;  //in seconds
            return;
        } else {                        //исследующий поиск снова?
            for (i = 0; i < n; i++) {
                new_x[i] = x_before[i];
            }
        }
    }
}

double random_real(double low, double high) {
    double d = (double) rand() / ((double) RAND_MAX + 1);
    return (low + d * (high - low));
}

void luus_jaakola_method(const double* x_first, int n, char* str, double* res, float eps) {
    clock_t t = clock();
    double (*function)(double*, int) = define_function_name(str);
    srand((unsigned int) time(0));                                   //init rand
    int N = 1000, R = 1000, q = 100, i, p, k, s;                     // N - кол-во итераций за прогон, R - кол-во генерируемых случайных точек на каждой итерации,
    double reduce_coef = 0.95;                                       // q - кол-во прогонов, reduce_coef - коэф-т сжатия области поиска
    double x_new[n], x_before[n], r[n];
    for (i = 0; i<n; i++) {
        x_new[i] = x_first[i];
        r[i] = 20.0;                                    //фиксированный размер области поиска для каждой координаты
    }
    double f_min = (*function)(x_new, n);
    for (s=0; s<q; s++) {
        for (i = 0; i<n; i++) {
            x_before[i] = x_new[i];
        }
        for (p = 0; p < N; p++) {
            for (k = 0; k < R; k++) {
                double point[n], f_point;
                for (i = 0; i < n; i++) {
                    point[i] = x_new[i] + random_real(-1, 1) * r[i];
                }
                f_point = (*function)(point, n);
                if (f_point < f_min) {
                    f_min = f_point;
                    for (i = 0; i < n; i++) {
                        x_new[i] = point[i];
                    }
                }
            }
            for (i = 0; i < n; i++) {
                r[i] *= reduce_coef;                                                // уменьшим область поиска
            }
        }
        for (i = 0; i < n; i++) {
            r[i] = fabs(x_new[i] - x_before[i]);                                    // уменьшим область поиска
        }
        if (norm(r,n) < eps) {
            for (i = 0; i<n; i++) {
                res[i] = x_new[i];
            }
            t = clock() - t;
            execution_time = ((double)t)/CLOCKS_PER_SEC;  //in seconds
            return;
        }
    }
}

double euclidian_distance(double* x1, double* x2, int n) {
    double distance = 0.0;
    for (int i=0; i<n; i++) {
        distance += pow(x1[i] - x2[i], 2);
    }
    return sqrt(distance);
}

void competing_points_method(const double* x_first, int n, char* s, double* res) {
    clock_t t = clock();
    double (*function)(double*, int) = define_function_name(s);
    int cluster_count = 20, r = 30;                      // кол-во кластеров должно быть больше чем предполагаемое количество локальных минимумов
    double clusters[cluster_count][n], min_dist = 0.1;   //поиск будет проходить в области +-r относительно x_first
    double step = 2.0*r / (cluster_count - 1);
    for (int k = 0; k<cluster_count; k++) {
        double point[n];
        for (int i = 0; i < n; i++) {
            point[i] = x_first[i]-r + k * step;
        }
        hooke_jeeves_method(point, n, s, res, 0.001);
        for (int i = 0; i < n; i++) {
            clusters[k][i] = res[i];
        }
    }

    while (1) {
        int index[cluster_count];
        for (int i = 0; i < cluster_count; i++) {
            index[i] = -1;
        }
        int cur_index = 0;
        for (int i = 0; i < cluster_count; i++) {
            if (index[i] == -1) {
                index[i] = cur_index;
            }
            for (int k = i + 1; k < cluster_count; k++) {
                if (euclidian_distance(clusters[i], clusters[k], n) < min_dist) {
                    index[k] = index[i];
                }
            }
            cur_index++;
        }
        double point[n], new_clusters[cluster_count][n];
        double f_min;
        int size = 0;
        for (cur_index = 0; cur_index < cluster_count; cur_index++) {
            f_min = INFINITY;
            for (int i = 0; i < cluster_count; i++) {
                if (index[i] == cur_index) {
                    if ((*function)(clusters[i], n) < f_min) {
                        f_min = (*function)(clusters[i], n);
                        for (int k = 0; k < n; k++) {
                            point[k] = clusters[i][k];
                        }
                    }
                }
            }
            if (f_min != INFINITY) {
                for (int k = 0; k < n; k++) {
                    new_clusters[size][k] = point[k];
                }
                size++;
            }
        }
        if (size == 1) {
            for (int i = 0; i < n; i++) {
                res[i] = new_clusters[0][i];
            }
            t = clock() - t;
            execution_time = ((double)t)/CLOCKS_PER_SEC;  //in miliseconds
            return;
        } else {
            for (int k = 0; k < size; k++) {
                for (int i = 0; i < n; i++) {
                    clusters[k][i] = new_clusters[k][i];
                }
            }
            cluster_count = size;
            min_dist *= 10;
        }
    }
}


