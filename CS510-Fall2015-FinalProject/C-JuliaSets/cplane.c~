#include <stdio.h>
#include <stdlib.h>
#include "cplane.h"



//Construct a CPLANE to store the values of the complex numbers
CPLANE new_cplane(VALUE xmin, VALUE xmax,
		VALUE ymin, VALUE ymax,
		VALUE creal, VALUE cimag, 
		INDEX xpoints, INDEX ypoints) {

  CPLANE cp;
  cp.xmin = xmin;
  cp.xmax = xmax;
  cp.ymin = ymin;
  cp.ymax = ymax;
  cp.rows = xpoints;
  cp.cols = ypoints;
  cp.real = creal;
  cp.imag = cimag;
  cp.maxiter=2048;

  cp.mat = (COMPLEX *)calloc(xpoints * ypoints, sizeof(COMPLEX));
  if (cp.mat == NULL) {
    fprintf(stderr, "Failed to allocate new_cplane\n");
  }
	unsigned long i, j;
	for (i = 0; i < xpoints; i++){
		for (j = 0; j < ypoints; j++){
			COMPLEX ab;
			ab.x = xmin+(double)i*(xmax-xmin)/(double)(xpoints-1);
			ab.y = ymin+(double)j*(ymax-ymin)/(double)(ypoints-1);

			*(cp.mat + (xpoints * j) + i) = ab;
	}
}
  return cp;

}

void delete_cplane(CPLANE m) {
  // Free memory that was allocated, to avoid memory leak
  free(m.mat);
}

void set(CPLANE *m, const INDEX row, const INDEX col, const COMPLEX v) {
  // Find the pointer to the block of memory containing 
  // the matrix mat, then jump forward row number of rows
  // and col number of columns.  Inside that block of memory
  // insert the value v.
  if (row < 0 || col < 0 || row >= m->rows || col >= m->cols) {
    fprintf(stderr, "ERROR: indexing complex plane outside bounds");
    return;
  }
  *(m->mat + (m->cols * row) + col) = v;
}


COMPLEX get(const CPLANE *m, const INDEX row, const INDEX col) {
  // Find the pointer to the block of memory containing 
  // the matrix mat, then jump forward row number of rows
  // and col number of columns.  Return the value inside.
  if (row < 0 || col < 0 || row >= m->rows || col >= m->cols) {
    fprintf(stderr, "ERROR: indexing matrix outside bounds");
  }
  return *(m->mat + m->cols * row + col);
}

void juliaiterate(const CPLANE *m){
	COMPLEX randseed;
	randseed.x=m->real; randseed.y=m->imag;
	unsigned long i, j;
	for (i = 0; i < m->cols; i++){
		for (j = 0; j < m->rows; j++){
		COMPLEX c = get(m,i,j);
		int n=1;

		c=juliamap(c, randseed);

		while(c.y<2.0 && n< m->maxiter){
		c=juliamap(c,randseed);
		n++;
		};
		c = get(m, i, j);
		printf("%Lf, %Lf, %d \n",c.x, c.y,n*(n < m->maxiter));
		}
	}
}

COMPLEX mult2(COMPLEX a, COMPLEX b){
	COMPLEX ab;
	ab.x = a.x*b.x-a.y*b.y;
	ab.y = a.x*b.y+b.x*a.y;

	return ab;
}

COMPLEX square(COMPLEX a){
	return mult2(a,a);
}

COMPLEX add2(COMPLEX a, COMPLEX b){
	COMPLEX ab;
	ab.x = a.x + b.x;
	ab.y = a.y + b.y;

	return ab;
}

COMPLEX juliamap(COMPLEX z, COMPLEX c){
	return add2(square(z), c);
}

int complex_print(COMPLEX z){
	printf("%Lf + %Lf \n", z.x, z.y);
	return 0;
}

void print_cplane(const CPLANE *m) {
  INDEX r, c, maxr, maxc;
  maxr = m->rows;
  maxc = m->cols;

  printf("Matrix (rows: %d, cols: %d) \n", maxr, maxc);
  for(r=0; r<maxr; r++) {
    for(c=0; c<maxc; c++) {
      // print values of matrix separated by tabs
      // with each row on a separate line
      complex_print(get(m, r, c));
      printf(" ");
    }
    puts("");
  }
  puts("");
}

int test_cplane(CPLANE a){
	


	juliaiterate(&a);
 
 	delete_cplane(a);

	return 0;
}
