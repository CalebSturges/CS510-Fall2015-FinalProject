#include <iostream>
#include <complex>
#include <cstdio>

#include "cplane.hpp"
#include "julia.hpp"

using namespace std;

int main(int argc, char *argv[]){
        
        long double xmin, xmax, ymin, ymax;  // Bounds for cplane
        unsigned long int xpoints, ypoints;  // Points for cplane

	if(argc!=7){
       		return 0;
   	 }


   	//Assigns bounds for the real component
   	stringstream(argv[1]) >> xmin;		stringstream(argv[2]) >> xmax;

	//Assigns bounds for the imaganary component
 	stringstream(argv[3]) >> ymin;		stringstream(argv[4]) >> ymax;

	//Assigns points for the real and imaganary components of the plane
	stringstream(argv[5]) >> xpoints;	stringstream(argv[6]) >> ypoints;

  	complex<long double> randSeed(0., 0.);
	CPlane<complex<long double> > newcplane(xmin,xmax,ymin,ymax,xpoints,ypoints,randSeed);

	int curiter;
	int maxiter;
	maxiter = 64;
	complex<long double> runningz(0., 0.);
	for(int y = 0; y<ypoints; y++){
        	for(int x = 0; x<xpoints; x++){
            		
			runningz = juliamap(randSeed, newcplane(x,y));
			
			while((curiter<maxiter)&&abs(runningz)<2.0){
				runningz = juliamap(runningz, newcplane(x,y));
				curiter++;
			}
            	
            		// Print out data
            		cout << newcplane(x,y).real() << "," << newcplane(x,y).imag() 
			<< "," << curiter << endl;
			curiter=0;
        	}
    	}
	return 0;
}
