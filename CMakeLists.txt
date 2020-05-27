cmake_minimum_required(VERSION 3.5.1)               #проверка версии cmake
project(diplom1 C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_EXE src/test/test.c Unity/src/unity.c)		                    # Установка переменной со списком исходников для исполняемого файла

include_directories(src/test_funcs_lib)			    # Расположение заголовочных файлов
include_directories(Unity/src)

add_executable(func_opt_o ${SOURCE_EXE})	            # Создает исполняемый файл с именем diplom1

add_subdirectory(src/test_funcs_lib)				# Добавление подпроекта, указывается имя дирректории
add_subdirectory(Unity)
include(CTest)

target_link_libraries(func_opt_o test_funcs_optimize m)		# Линковка программы с библиотекой



