#include <iostream>
#include <cmath>
#include <complex>
#include <cstdio>

#include "julia.hpp"
using namespace std;

// used in julia and mandelbrot set
complex<long double> juliamap(complex<long double> z, complex<long double> c){
	complex<long double> juliamaped;

	juliamaped = z*z + c;

	return juliamaped;
}
