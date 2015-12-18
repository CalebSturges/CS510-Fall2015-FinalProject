// Define types as abstraction layer to protect against implementation changes
typedef unsigned int INDEX;
typedef double VALUE;

typedef struct Complex
{
	long double x;
	long double y;
}COMPLEX;

// Use abstract types inside matrix definition for robustness
typedef struct cplane {
 	INDEX cols;
	INDEX rows;
	VALUE xmin;
	VALUE xmax;
	VALUE ymin;
	VALUE ymax;
	INDEX maxiter;
	VALUE real;
	VALUE imag;
	COMPLEX c;
 	COMPLEX *mat;
} CPLANE;


//Construct a CPLANE to store the values of the complex numbers
CPLANE new_cplane(VALUE xmin, VALUE xmax,
		VALUE ymin, VALUE ymax,  VALUE creal, VALUE cimag,
		INDEX xpoints, INDEX ypoints);

void delete_cplane(CPLANE m);

void set(CPLANE *m, const INDEX row, const INDEX col, const COMPLEX v);

COMPLEX get(const CPLANE *m, const INDEX row, const INDEX col);

COMPLEX mult2(COMPLEX a, COMPLEX b);

COMPLEX square(COMPLEX a);

COMPLEX add2(COMPLEX a, COMPLEX b);

COMPLEX juliamap(COMPLEX z, COMPLEX c);

void juliaiterate(const CPLANE *m);

int complex_print(COMPLEX z);

void print_cplane(const CPLANE *m);

int test_cplane(CPLANE a);
