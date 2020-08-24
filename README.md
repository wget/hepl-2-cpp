# HEPL - 2 - CPP Project - Calculator

A simple calculator

## Build instructions

Clone this directory, then clone the two libs we are making use.

    git clone https://github.com/wget/hepl-2-cpp-lib src/lib/utils/
    git clone https://github.com/gpakosz/whereami src/lib/whereami/

Make sure you have the SDL library **version 1.2** installed system wide.

Then, still from the root of this repository:

    make

To clean objs and executables:

    make mrproper

Requires a C++11 compiler. Only tested with GNU GCC. The makefile ensures the code is compiled in 2011 mode.

If you are using an old machine and you are unsure of the version of C++ being available, you can display the value of the `__cplusplus` keyword.

    #include <iostream>

    int main(void) {
        std::cout << __cplusplus << std::endl;
        return 0;
    }

To force the compilation in C++11, compile with `g++ -std=gnu++11 test_cpp_standard.cpp  -o test_cpp_standard`, execute the binary produced. It should return `201103`. If C++11 is not supported, you should have something like `g++: error: unrecognized command-line option ‘-std=gnu++11’; did you mean 'XXX'?`
