#include <stdio.h>
#include <stdlib.h>
#include "cplane.h"

int main(void) {
	// Construct a new nxm complex plane
	
	CPLANE *cp;
	cp = (CPLANE *)malloc(sizeof(CPLANE));
	printf("Please enter xmin: ");
	float xmin;
	scanf("%f",&xmin);

	printf("Please enter xmax: ");
	float xmax;
	scanf("%f",&xmax);

	printf("Please enter ymin: ");
	float ymin;
	scanf("%f",&ymin);

	printf("Please enter ymax: ");
	float ymax;
	scanf("%f",&ymax);

	printf("Please enter the col number: ");
	scanf("%d",&cp->cols);

	printf("Please enter the row number: ");
	scanf("%d",&cp->rows);
	
	printf("Please enter creal: ");
	float xmin;
	scanf("%f",&xmin);

	printf("Please enter cimag: ");
	float xmax;
	scanf("%f",&xmax);

	printf("You Entered: %f/ %f/ %f/ %f/ %d/ %d \n",
		xmin, xmax,
		ymin,ymax,
		cp->cols, cp->rows);
	CPLANE newcp = new_cplane(xmin,xmax,
				  ymin,ymax,
				  cp->cols,cp->rows);
	test_cplane(newcp);
	return 0;
}
