# CS510-Fall2015-FinalProject
Caleb Sturges

This project involves visualizing the mandelbrot and julia sets using C++ and C respectively to generate the sets and python to visual them.

C-Juliaset-  Directory for julia map functions programmed in C

    Makefile-      File that directs the compilation of all the C programs in this directory
    complex.c-     Definition of the functions that can be run on complex elements
    complex.h-     Header for complex 
    cplane.c-      Defintion for the complex plane
    cplane.h-      Header for cplane
    cplane.o-      Object file for cplane
    julia-         Compiled file for the juliamap code generation
    julia.c-       Functions that mutates the data points for the julia set


Cpp-Mandelbrot-  Directory for mandelbrot functions programmed in C++

    Makefile-       File that directs the compilation of all the C++ programs in this directory
    cplane.cpp-     Defintion for the complex plane
    cplane.hpp-     The header file for the cplane.cpp program
    julia.cpp-      The defintion for functions (e.g julimap) that can be peformed on complex numbers
    julia.hpp-      Header for the julia.cpp program
    mandelbrot-     Compiled file for the mandelbrot code generation
    mandelbrot.cpp- Functions that mutates the data points for the mandelbrot set
    
Datasets- Directory for visualization functions for the julias and mandelbrot sets programmed in python

    mandelbrot_xmin_xmax_ymin_ymax.jpg-  Pictures for each of the mandelbrot sets with different bounds
    juliaset_realseed_complexseed.jpg-   Pictures for each of the julia sets with different random seeds (all on the -2,2,-2,2 plane)
    plot_data.py-                        Program used to generate the visualizations in a jpg format based on the data points provided to the input file
    
 
generate_output.sh-          Program is used to generate the data points using the julia and mandelbrot executables

