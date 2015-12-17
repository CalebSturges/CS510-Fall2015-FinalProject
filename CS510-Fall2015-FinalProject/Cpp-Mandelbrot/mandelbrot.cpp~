#include <iostream>
#include <complex>
#include <cstdio>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>

#include "cplane.hpp"
#include "julia.hpp"

int main(int argc, char *argv[]){
        
        long double xmin, xmax, ymin, ymax;  // Bounds for cplane
        unsigned long int xpoints, ypoints;  // Points for cplane

	if(argc!=7){
       		return 0;
   	 }

   	 boost::numeric::ublas::matrix<std::complex<long double> > test2;

   	 //Assigns bounds for the real component
   	 std::stringstream(argv[1]) >> xmin;	std::stringstream(argv[2]) >> xmax;

	//Assigns bounds for the imaganary component
 	std::stringstream(argv[3]) >> ymin;	std::stringstream(argv[4]) >> ymax;

	//Assigns points for the real and imaganary components of the plane
	std::stringstream(argv[5]) >> xpoints;	std::stringstream(argv[6]) >> ypoints;

  
	cplane newcplane;
	newcplane.set(xmin,xmax,ymin,ymax,xpoints,ypoints);

	lcomplex compC (0,0); // Initialize the entries
	int curiter;
	for(int y = 0; y<newcplane.ypoints; y++){
        	for(int x =0; x<newcplane.xpoints; x++){
            		
			lcomplex runningcomplex = newcplane.mat(x,y);
			
			while(curiter<256&&std::abs(runningcomplex)>2.0){
				runningcomplex = juliamap(runningcomplex, newcplane.mat(x,y));
				curiter++;
			}
            	
            		// Print out data
            		std::cout << newcplane.mat(x,y).real() << " " << newcplane.mat(x,y).imag() 
			<< " " << curiter*(curiter>=maxiter) << std::endl;
        }
    }
}
