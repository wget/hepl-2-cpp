# HEPL - 2 - CPP Project - Calculator

A simple calculator

## Build instructions

Clone this directory, then clone the two lib we are making use.

    git clone https://github.com/wget/hepl-2-cpp-lib src/lib/utils/
    git clone https://github.com/gpakosz/whereami src/lib/whereami/

Then, still from the root of this repository:

    make

To clean objs and executables:

    make mrproper

Requires a C++11 compiler. Only tested with GNU GCC.
