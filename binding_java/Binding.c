#include <stdio.h>
#include <jni.h>
#include <string.h>
#include "Binding.h"
#include "test_funcs_optimize.h"


jdoubleArray call_method(JNIEnv* env, jobject obj, jdoubleArray array,
                                    jstring string, jdoubleArray res, char* method, jfloat eps) {
    jsize len = (*env)->GetArrayLength(env, array);
    jdouble* body = (*env)->GetDoubleArrayElements(env, array, 0);
    jdouble* body_res = (*env)->GetDoubleArrayElements(env, res, 0);
    const char* str = (*env)->GetStringUTFChars(env, string, 0);
    char s[50];                                                                    //иначе warning
    strcpy(s, str);
    if (!strcmp("HJ_M", method)) {
        hooke_jeeves_method(body, len, s, body_res, eps);
    } else if (!strcmp("LJ_M", method)) {
        luus_jaakola_method(body, len, s, body_res, eps);
    } else if (!strcmp("CP_M", method)) {
        competing_points_method(body, len, s, body_res);
    }
    (*env)->ReleaseDoubleArrayElements(env, array, body, 0);
    (*env)->ReleaseDoubleArrayElements(env, res, body_res, 0);
    (*env)->ReleaseStringUTFChars(env, string, str);
    return res;
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_hooke_1jeeves_1method
                        (JNIEnv* env, jobject obj, jdoubleArray array, jstring string, jdoubleArray res, jfloat eps) {
    return call_method(env, obj, array, string, res, "HJ_M", eps);
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_luus_1jaakola_1method
                  (JNIEnv* env, jobject obj, jdoubleArray array, jstring string, jdoubleArray res, jfloat eps) {
    return call_method(env, obj, array, string, res, "LJ_M", eps);
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_competing_1points_1method
                                      (JNIEnv* env, jobject obj, jdoubleArray array, jstring string, jdoubleArray res) {
     return call_method(env, obj, array, string, res, "CP_M", 0);
}

JNIEXPORT jdouble JNICALL Java_Binding_get_1execution_1time(JNIEnv* env, jobject obj) {
     return get_execution_time();
}

typedef double (*func)(double*, int);

jdouble call_function(JNIEnv* env, jobject obj, jdoubleArray array, func f) {
    jsize len = (*env)->GetArrayLength(env, array);
    jdouble* body = (*env)->GetDoubleArrayElements(env, array, 0);
    double res;
    res = (*f)(body, len);
    (*env)->ReleaseDoubleArrayElements(env, array, body, 0);
    return res;
}

JNIEXPORT jdouble JNICALL Java_Binding_rastrigin_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_function(env, obj, array, rastrigin_function);
}

JNIEXPORT jdouble JNICALL Java_Binding_sphere_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_function(env, obj, array, sphere_function);
}

JNIEXPORT jdouble JNICALL Java_Binding_stibinski_1tanga_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_function(env, obj, array, stibinki_tanga_function);
}

JNIEXPORT jdouble JNICALL Java_Binding_ekli_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_function(env, obj, array, ekli_function);
}

JNIEXPORT jdouble JNICALL Java_Binding_rosenbrock_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_function(env, obj, array, rosenbrock_function);
}

JNIEXPORT jdouble JNICALL Java_Binding_bill_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_function(env, obj, array, bill_function);
}

JNIEXPORT jdouble JNICALL Java_Binding_goldman_1price_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_function(env, obj, array, goldman_price_function);
}

JNIEXPORT jdouble JNICALL Java_Binding_boot_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_function(env, obj, array, boot_function);
}

JNIEXPORT jdouble JNICALL Java_Binding_bookin_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_function(env, obj, array, bookin_function);
}

JNIEXPORT jdouble JNICALL Java_Binding_matias_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_function(env, obj, array, matias_function);
}

JNIEXPORT jdouble JNICALL Java_Binding_levi_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_function(env, obj, array, levi_function);
}

JNIEXPORT jdouble JNICALL Java_Binding_three_1hump_1camel_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_function(env, obj, array, three_humped_camel_function);
}

JNIEXPORT jdouble JNICALL Java_Binding_easom_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_function(env, obj, array, easom_function);
}

typedef void (*min_x)(double*, int);

jdoubleArray call_min_x(JNIEnv* env, jobject obj, jdoubleArray array, min_x f) {
    jsize len = (*env)->GetArrayLength(env, array);
    jdouble* body = (*env)->GetDoubleArrayElements(env, array, 0);
    (*f)(body, len);
    (*env)->ReleaseDoubleArrayElements(env, array, body, 0);
    return array;
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_get_1min_1x_1rastrigin_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_min_x(env, obj, array, get_min_x_rastrigin_function);
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_get_1min_1x_1sphere_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_min_x(env, obj, array, get_min_x_sphere_function);
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_get_1min_1x_1stibinski_1tanga_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_min_x(env, obj, array, get_min_x_stibinski_tanga_function);
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_get_1min_1x_1ekli_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_min_x(env, obj, array, get_min_x_ekli_function);
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_get_1min_1x_1rosenbrock_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_min_x(env, obj, array, get_min_x_rosenbrock_function);
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_get_1min_1x_1bill_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_min_x(env, obj, array, get_min_x_bill_function);
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_get_1min_1x_1goldman_1price_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_min_x(env, obj, array, get_min_x_goldman_price_function);
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_get_1min_1x_1boot_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_min_x(env, obj, array, get_min_x_boot_function);
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_get_1min_1x_1bookin_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_min_x(env, obj, array, get_min_x_bookin_function);
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_get_1min_1x_1matias_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_min_x(env, obj, array, get_min_x_matias_function);
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_get_1min_1x_1levi_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_min_x(env, obj, array, get_min_x_levi_function);
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_get_1min_1x_1three_1hump_1camel_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_min_x(env, obj, array, get_min_x_three_hump_camel_function);
}

JNIEXPORT jdoubleArray JNICALL Java_Binding_get_1min_1x_1easom_1function(JNIEnv* env, jobject obj, jdoubleArray array) {
    return call_min_x(env, obj, array, get_min_x_easom_function);
}
