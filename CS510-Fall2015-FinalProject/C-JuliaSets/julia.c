#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "cplane.h"

int main(int argc, char *argv[]) {
	// Construct a new nxm complex plane
	
	CPLANE *cp;
	cp = (CPLANE *)malloc(sizeof(CPLANE));
	//printf("Please enter xmin: ");
	float xmin;
	sscanf(argv[1],"%f",&xmin);

	//printf("Please enter xmax: ");
	float xmax;
	sscanf(argv[2],"%f",&xmax);

	//printf("Please enter ymin: ");
	float ymin;
	sscanf(argv[3],"%f",&ymin);

	//printf("Please enter ymax: ");
	float ymax;
	sscanf(argv[4],"%f",&ymax);

	//printf("Please enter the col number: ");
	sscanf(argv[5],"%d",&cp->cols);

	//printf("Please enter the row number: ");
	sscanf(argv[6],"%d",&cp->rows);
	
	//printf("Please enter creal: ");
	float creal;
	sscanf(argv[7],"%f",&creal);

	//printf("Please enter cimag: ");
	float cimag;
	sscanf(argv[8],"%f",&cimag);

	//printf("You Entered: %f/ %f/ %f/ %f/ %d/ %d %f/ %f/ \n",
	//	xmin, xmax,
	//	ymin,ymax,
	//	cp->cols, cp->rows,creal,cimag);
	CPLANE newcp = new_cplane(xmin,xmax,
				  ymin,ymax,
				  creal,cimag,
				  cp->cols,cp->rows);
	test_cplane(newcp);
	return 0;
}
