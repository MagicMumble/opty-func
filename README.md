# opty-func
Library for optimization methods testing


## Building and running the project
Install library to your `~/.local/share` directory using git:
            
    git clone https://github.com/MagicMumble/opty-func ~/.local/share/opty-func
 
Come to newly created directory:
 
    cd ~/.local/share/opty-func
 
To build the project you'll need to install Unity - static library with different 
interfaces for running test and reporting results using assertions. It's linked 
with the testing code (`src/test/test.c`). 

    git clone https://github.com/ThrowTheSwitch/Unity.git

The other thing you need to install are utilities cmake and make:

    sudo apt install cmake
    sudo apt install make

Minimum required cmake version - 3.12.

To build the project use script named run. Several options are allowed:

    ./run build - for building the project. 
 This command creates build directory and    build the project. Now you have shared object library named test_funcs_optimize.so in `~/build/src/test_funcs_lib/`.

    ./run start - for running the project (only after building it).

    ./run       - for builing and running the project.

    ./run clean - for cleaning the build directory.

    ./run help  - for listing possible options.
    
In case the execute permission was denied change the access permission by command:
   
    chmod +x run

After running the project as a result in your terminal you'll get several characteristics about testing every function and 
method from the compiled library:
* PASS/FAIL
* Calculated global minimum of current function with current method
* Real global minimum
* Calculation error 
* Execution time 

At the end of output - the amount of conducted tests and failures.

 ## Using .so library in remote .c file
 
 Example of c code invoking some functions from .so library. Don't forget to include header file!
 
    #include <stdio.h>
    #include "test_funcs_optimize.h"

     int main() {
             int n2 = 2;                                         // init data
             double x_start2[] = {3.0, 4.0};
             double mas_res[n2];
             
             hooke_jeeves_method(x_start2, n2, "Matias_func", mas_res, 0.001);      // call some functions
             double calculated_glob_min = sphere_function(mas_res, n2);
             get_min_x_sphere_function(mas_res, n2);
             double real_glob_min = sphere_function(mas_res, n2);
             double time = get_execution_time();
             
             printf("calc_min = %lf, real_min %lf, exec_time = %lf seconds\n", calculated_glob_min, real_glob_min, time);
             return 0;
      }
            
Let's say your file is named main.c. You can compile it with the command

    gcc -L ~/.local/share/opty-func/build/src/test_funcs_lib -I ~/.local/share/opty-func/src/test_funcs_lib/ -o main main.c -ltest_funcs_optimize
            
The option -L tells the compiler where to look for the .so library. The option -I causes given directory to be searched after the current directory and ahead of the standard system directories. The `-ltest_funcs_optimize` option links the program with the library `libtest_funcs_optimize.so` (the .so object name always starts with the prefix `lib` so compiler knows exactly that it's looking for a .so library).

    export LD_LIBRARY_PATH=~/.local/share/opty-func/build/src/test_funcs_lib:$LD_LIBRARY_PATH
           
The environment variable `LD_LIBRARY_PATH` tells the compiler where to load the .so library from for first time before the standard set of directories. Now run the object file `main.o`:
             
    ./main
            
You can find this example in the directory `src/example_c`. To simplify running .c file use attached script file. 

 ## Using .so library in remote .py file
 
 Example of python code invoking some functions from .so library:
      
      import binding
      
      my_list = [9, 2, 3]
      print("Hooke_Jeeves_method for sphere func: ", binding.hooke_jeeves_method(my_list, "Sphere_func", 0.001))
      
      x = [3, 4]
      print("Boot: ", binding.boot_function(x))
      print("Bookin: ", binding.bookin_function(x))
 
Now set the environment variable `PYTHONPATH`.
 
     export PYTHONPATH=~/.local/share/opty-func/binding_py/:$PYTHONPATH

This command let the interpreter know where it can find the file `binding.py` which provides access to .so library functions using ctypes. Assuming you're in the same directory where resides your file you can run it with the simply command

     python3 main.py
     
To find more complex example go the directory `src/example_py`. Use attached script file. 
 
 ## Using .so library in remote .java file
 
 ## Using .so library in remote .go file
 
 ## Using .so library in remote .js file
 
 

                    Представленные методы:

    метод Хука-Дживса,
    метод конкурирующих точек (с использованием кластеризации),
    метод Luus-Jaakola.

==============================================================

                      Тестовые функции:

    функция Растригина,
    функция Экли,
    функция сферы,
    функция Розенброка,
    функция Била,
    функция Гольдмана-Прайса,
    функция Бута,
    функция Букина,
    функция Матьяса,
    функция Леви,
    функция трехгорбого верблюда,
    функция Изома.
