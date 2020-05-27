# opty-func

            Library for optimization methods testing
            
Install library to your ~/.local/share directory using git:
            
git clone https://github.com/MagicMumble/opty-func ~/.local/share/opty-func
 
Come to newly created directory:
 
cd ~/.local/share/opty-func
 
To build the project you'll need to install Unity - static library with different 
interfaces for running test and reporting results using assertions. It's linked 
with the testing code (src/test/test.c). 

git clone https://github.com/ThrowTheSwitch/Unity.git

The other thing you need to install are utilities cmake and make:

sudo apt install cmake
sudo apt install make

Minimum required cmake version - 3.12.

To build the project use script named run. Several options are allowed:

./run build - for building the project. This command creates build directory and 
build the project. Now you have shared object library named test_funcs_optimize.so
in ~/build/src/test_funcs_lib/.

./run start - for running the project (only after building it).

./run       - for builing and running the project.

./run clean - for cleaning the build directory.

./run help  - for listing possible options.

 

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
