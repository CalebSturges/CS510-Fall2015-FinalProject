#include <stdio.h>

typedef struct Complex
{
	long double x;
	long double y;
}complex;



complex mult2(complex a, complex b){
	complex ab;
	ab.x = a.x*b.x-a.y*b.y;
	ab.y = a.x*b.y+b.x*a.y;

	return ab;
}

complex square(complex a){
	return mult2(a,a);
}

complex add2(complex a, complex b){
	complex ab;
	ab.x = a.x + b.x;
	ab.y = a.y + b.y;

	return ab;
}

complex juliamap(complex z, complex c){
	return add2(square(z), c);
}

int complex_print(complex z){
	printf("z = %f  + %f \n", z.x, z.y);
	return 0;
}

int test(complex a, complex b){

	complex_print(mult2(a,b));
	complex_print(square(a));
	complex_print(add2(a,b));
	complex_print(juliamap(a,b));

	return 0;
}

int main(void){
	complex ab;
	ab.x=2;
	ab.y=1;
	test(ab,ab);
	return 0;
}
