#include <stdio.h>
#include <stdlib.h>
#include "cplane.h"



//Construct a CPLANE to store the values of the complex numbers
CPLANE new_cplane(VALUE xmin, VALUE xmax,
		VALUE ymin, VALUE ymax, VALUE creal, VALUE cimag, 
		INDEX xpoints, INDEX ypoints) {

  CPLANE cp;
  cp.xmin = xmin;
  cp.xmax = xmax;
  cp.ymin = ymin;
  cp.ymax = ymax;
  cp.rows = xpoints;
  cp.cols = ypoints;
  cp.maxiter=256;

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
			complex_print(ab);
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
	randseed.x=0.; randseed.y=0.;
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
	
  puts("Initial complex plane:");
  print_cplane(&a);

  /*puts("Modified matrix:");
  *set(&a, 1, 1, 20.0);
  *set(&a, 2, 2, 40.0);
  *set(&a, 0, 4, 60.0);
  *set(&a, 2, 5, 80.0);
  *print_cplane(&a);*/

  puts("Element a(2,2):");
  complex_print(get(&a, 2, 2));
  puts("");
  puts("Element a(0,4):");
  complex_print(get(&a, 0, 4));
  puts("");
	juliaiterate(&a);
  // Destruct matrix when done
  delete_cplane(a);

	return 0;
}

//int main(void) {
	// Construct a new 3x6 matrix
//  CPLANE a = new_cplane(1.,10.,1.,10.,5,5);
//	test_cplane(a);
//	return 0;
//}
