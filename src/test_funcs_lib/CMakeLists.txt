cmake_minimum_required(VERSION 3.5.1)

project(test_funcs_lib)

set(SOURCE_LIB test_funcs_optimize.c)		             # Установка переменной со списком исходников

add_library(test_funcs_optimize SHARED ${SOURCE_LIB})    # Создание динамической библиотеки

target_link_libraries(test_funcs_optimize m)
