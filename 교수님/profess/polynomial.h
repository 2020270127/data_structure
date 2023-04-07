#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 101
#define COMPARE(x,y)((x)>(y)?1:(x)<(y)?-1:0)

typedef struct _term {
	unsigned int expon;
	float coef;
} term;
term terms[MAX_DEGREE];
unsigned int avail = 0;
typedef struct _polynomial {
	unsigned int start;
	unsigned int finish;
} polynomial;

void attach(float coefficient, int exponent) {
	if (avail >= MAX_DEGREE) {
		exit(0);
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}

void padd(polynomial A, polynomial B, polynomial* D) {
	float coefficient;
	D->start = avail;
	while (A.start <= A.finish && B.start <= B.finish) {
		switch (COMPARE(terms[A.start].expon, terms[B.start].expon))
		{
		case -1:
			attach(terms[B.start].coef, terms[B.start].expon);
			B.start++;
			break;
		case 0:
			coefficient = terms[A.start].coef + terms[B.start].coef;
			if (coefficient)
				attach(coefficient, terms[A.start].expon); // A,B의 expon값이 같으므로 A,B중 어떤 expon값을 고르던 동일
			A.start++;
			B.start++;
			break;
		case 1:
			attach(terms[A.start].coef, terms[A.start].expon);
			A.start++;
		}
	}
	D->finish = avail - 1; //avail은 다음칸을 가리키고 있으므로 한칸 전으로 인덱스 설정
}
void print_info(polynomial* D) {

	for (int i = D->start; i < (D->finish) + 1; i++) {
		printf("coefficient of D : %f\n", terms[i].coef);
		printf("exponent of D : %d\n", terms[i].expon);
	}
}