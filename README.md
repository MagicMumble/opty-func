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
 This command creates build directory and    build the project. Now you have shared object library named test_funcs_optimize.so in `./build/src/test_funcs_lib/`.

    ./run start - for running the project (only after building it).

    ./run       - for building and running the project.

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
 
 Example of c code invoking some functions from .so library. Don't forget to include header file.
 
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
            
You can find this example in the directory `./src/example_c`. To simplify running .c file use attached script file. 

 ## Using .so library in remote .py file
 
 Example of python code invoking some functions from .so library (let it be `main.py`):
      
      import binding
      
      my_list = [9, 2, 3]
      print("Hooke_Jeeves_method for sphere func: ", binding.hooke_jeeves_method(my_list, "Sphere_func", 0.001))
      print("Luus_Jaakola_method for sphere func: ", binding.luus_jaakola_method(my_list, "Sphere_func", 0.001))
      print("Competing_points_method for sphere func: ", binding.competing_points_method(my_list, "Sphere_func"))
      print("Time of competing points method for sphere_func: ", binding.get_execution_time())
      
      x = [3, 4]
      print("Rastrigin: ", binding.rastrigin_function(x))
      print("Stibinski_Tanga: ", binding.stibinski_tanga_function(x))
      print("Boot: ", binding.boot_function(x))
      print("Bookin: ", binding.bookin_function(x))
 
Now set the environment variable `PYTHONPATH`.
 
     export PYTHONPATH=~/.local/share/opty-func/binding_py/:$PYTHONPATH

This command let the interpreter know where it can find the file `binding.py` which provides access to .so library functions using ctypes. Assuming you're in the same directory where resides your file you can run it with the simple command

     python3 main.py
     
To find more complex example go the directory `./src/example_py`. Use attached script file.

## Using .so library in remote .go file

There is an example of go code implementing some functions from .so library. Let the file name be `main.go`.

    package main
    import (
         "binding"
         "fmt"
     )

     func main() {
            mas := []float64{3.0, 3.0}
            fmt.Println(binding.Sphere_function(mas))
            fmt.Println(binding.Matias_function(mas))
            fmt.Println(binding.Levi_function(mas))

	    fmt.Println(binding.Luus_jaakola_method(mas, "Sphere_func", 0.001))  
	    fmt.Println(binding.Competing_points_method(mas, "Sphere_func"))

	    fmt.Println("EXEC TIME =", binding.Get_execution_time())
	    fmt.Println(binding.Get_min_x_rastrigin_function(mas))
      }

First of all you need to set an environment variable `GOPATH`. Go compiler is always checking two paths, `$GOROOT/src` and `GOPATH/src`, so one of them should lead to the package `binding` which is linked with the .so library by means of LDFLAGS and CFLAGS. `./binding_go/src/binding/binding.go` imports a pseudo-package "C" therefore the user can take a references to C types.

    export GOPATH=~/.local/share/opty-func/binding_go
    
Now build the example program with the command

    go build main.go

After that you need to set an environment variable `LD_LIBRARY_PATH` to the path where compiler can finc .so library. Run the program.

    export LD_LIBRARY_PATH=~/.local/share/opty-func/build/src/test_funcs_lib:$LD_LIBRARY_PATH
    ./main
    
You can find an example in the directory `./src/example_go/example.go`. Use the script for help.

 ## Using .so library in remote .java file
 
 Let's observe some example java file Binding.java which invokes several functions from .so library.
      
    import java.io.File;

    public class Binding {

        public native double rastrigin_function(double[] mas);
        public native double sphere_function(double[] mas);
    
        public native double[] luus_jaakola_method(double[] mas, String s, double[] res, float err);
        public native double[] competing_points_method(double[] mas, String s, double[] res);

        public native double[] get_min_x_ekli_function(double[] res);

        static {
            System.load("/home/" + System.getProperty("user.name") + "/.local/share/opty-func/binding_java/lib_bind_func_opt.so");
        }

        private static void print_mas(String method, double[] mas) {
            System.out.println(method + ":");
            for (double ma : mas) {
                System.out.print(ma + " ");
            }
            System.out.println();
        }

        public static void main(String[] args) {
            Binding b = new Binding();
            double[] mas = {6.0, 2.0};
            double res[] = new double[mas.length];

            System.out.println(b.rastrigin_function(mas));
            System.out.println(b.sphere_function(mas));
	
            print_mas("Luus_Jaakola_method", b.luus_jaakola_method(mas, "Rastrigin_func", res, 0.001f));
            print_mas("Competing_points_method", b.competing_points_method(mas, "Rastrigin_func", res));

            System.out.println("Time of competing points method: " + b.get_execution_time());

            print_mas("Mix x for elki func", b.get_min_x_ekli_function(res));
        }
    }
    
Assuming you're in the same directory with your `Binding.class` file use the command to create a C header file based on native methods declared in `Binding.class`.
  
    javac Binding.java -h ~/.local/share/opty-func/binding_java/
    
You need only to declare native methods which you're going to use in your program. Header file will be created in the directory `./binding_java/`. According to newly created header file the C file should be written defining all the declared functions in header file. You already downladed this C file with package `opty-func`.

The next step is to create an object file with position independent code using flag -fpic. That means that the generated machine code is not dependent on being located at a specific address in order to work. As a result you'll have an object file `Binding.o` in the directory `./binding_java/`. This proccess was once made automatically with cmake to create shared object library in this project.

    gcc -I /usr/lib/jvm/java-8-openjdk-amd64/include -I /usr/lib/jvm/java-8-openjdk-amd64/include/linux -I ~/.local/share/opty-func/src/test_funcs_lib/ -o ~/.local/share/opty-func/binding_java/Binding.o -c -fpic  ~/.local/share/opty-func/binding_java/Binding.c
    
Now you need to build .so library that invokes the first one created in first paragraph (the former linked to the latter with flag `-ltest_funcs_optimize` and the path after `-L` flag).

    gcc -L ~/.local/share/opty-func/build/src/test_funcs_lib -shared -o  ~/.local/share/opty-func/binding_java/lib_bind_func_opt.so ~/.local/share/opty-func/binding_java/Binding.o -ltest_funcs_optimize
    
Set an `LD_LIBRARY_PATH` to the `libtest_funcs_optimize.so` and run your program in current directory.

    export LD_LIBRARY_PATH=~/.local/share/opty-func/build/src/test_funcs_lib:$LD_LIBRARY_PATH
    java -classpath . Binding
    
Look for an example java code in the directory `./src/example_java`. Try the script `run` using options

    ./run lib - to compile the .so library based on your Binding.java file.
    ./run file - to run created class.
    ./run - to compile ./so and run the program.
 
 ## Using .so library in remote .js file
 
 Let's take a look at the node.js example code named main.js.
 
     var ffi = require("ffi");
     var ArrayType = require('ref-array');
     var DoubleArray = ArrayType('double');

     var user = process.env.USER || ""
     lib = "/home/" + user + "/.local/share/opty-func/build/src/test_funcs_lib/libtest_funcs_optimize.so"

     var my_lib = ffi.Library(lib, {
         "sphere_function": ['double', [DoubleArray, 'int']],
         "ekli_function": ['double', [DoubleArray, 'int']],
         "luus_jaakola_method": ['void', [DoubleArray, 'int', 'string', DoubleArray, 'float']],
         "get_execution_time": ['double', []]
     });

     var mas = [1.0, 2.0]
     var res = [0.0, 0.0]
     var array = new DoubleArray(mas);
     var array_res = new DoubleArray(res);

     console.log("Sphere func = ", my_lib.sphere_function(mas, mas.length))
     console.log("Ekli func = ", my_lib.ekli_function(mas, mas.length))

     my_lib.luus_jaakola_method(array, mas.length, "Ekli_func", array_res, 0.001)
     res_final = [array_res[0], array_res[1]]
     console.log("Luus Jaakola method: ", res_final, " , time = ", my_lib.get_execution_time())
     
Before running this program you need to install ffi, ref-array modules:
     
     npm install ffi
     npm install ref-array
     
If you're getting hit by the error *'Could not locate the bindings file'* try rebuilding dependencies. It might happen when some libraries failed during installation.

     npm rebuild
     
Now run the program with the command
   
     node main.js
     
The example of node.js code you can find in directory `./src/example_nodejs/example.js`. 
    
But be cautious of using it on your webpage, node-ffi is a Node.js addon for loading and calling dynamic libraries so you won't be able lauch it from inside the browser. One of the solutions is to separate client and server sides: client gets an initial data from user via webpage, sends the request to server side, server gets access to .so library and sends modified data back to the client. 
     
## Launching server invoking several functions from .so library and sending results to client side.

You can find webpage source files in the directory `./src/example_nodejs/webpage/`.
To run the server you need to install express, body-parser modules:

     npm install express
     npm install body-parser
     
After that start the server and open the file `./src/example_nodejs/webpage/opt_funcs.html` by clicking it. Press the button `build boxplot` on the opened page and wait a few seconds. You'll get four boxplots and four tables interpreting calculated results. 

     cd src/example_nodejs/webpage/
     node server.js
     
## Testing functions:

* Rastrigin function
* Ekli function
* Sphere function
* Rosenbrock function
* Bill function
* Goldman Price function
* Boot function
* Bookin function
* Matias function
* Levi function
* Three hump camel function
* Easom function

## Optimization methods:

* Hooke Jeeves method
* Competing points method
* Luus Jaakola method

