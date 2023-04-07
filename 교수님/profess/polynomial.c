#include "polynomial.h"
int main() {
	//A :       2x^2 + x + 1
	//B : x^3 + 3x^2     + 2
	
	//setting of A
	terms[0].coef = 2;
	terms[0].expon = 2;
	terms[1].coef = 1;
	terms[1].expon = 1;
	terms[2].coef = 1;
	terms[2].expon = 0;
	polynomial A;
	A.start = 0;
	A.finish = 2;

	//setting of B
	terms[3].coef = 1;
	terms[3].expon = 3;
	terms[4].coef = 3;
	terms[4].expon = 2;
	terms[5].coef = 2;
	terms[5].expon = 1;
	terms[6].coef = 2;
	terms[6].expon = 0;
	avail = 7;
	polynomial B;
	B.start = 3;
	B.finish = 6;
	
	polynomial D;
	padd(A, B, &D);
	print_info(&D);
}