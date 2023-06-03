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

void attach_to_new(float coefficient, int exponent) {
	if (avail >= MAX_DEGREE) {
		exit(1);
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
			attach_to_new(terms[B.start].coef, terms[B.start].expon);
			B.start++;
			break;
		case 0:
			coefficient = terms[A.start].coef + terms[B.start].coef;
			if (coefficient)
				attach_to_new(coefficient, terms[A.start].expon); // A,B의 expon값이 같으므로 A,B중 어떤 expon값을 고르던 동일
			A.start++;
			B.start++;
			break;
		case 1:
			attach_to_new(terms[A.start].coef, terms[A.start].expon);
			A.start++;
		}
	} //해당 루프의 최악의 시간복잡도: (A 항의 개수) + (B항의 개수) - 1(항상 마지막 하나가 대입되기 전에 루프 종료)
	for (; A.start <= A.finish; A.start++) 
		attach_to_new(terms[A.start].coef, terms[A.start].expon);
	for (; B.start <= B.finish; B.start++)
		attach_to_new(terms[B.start].coef, terms[B.start].expon);
	//남아있는 항들을 처리하는 루프, 최악의 시간 복잡도는 : (A항의 개수) + (B항의 개수)
	D->finish = avail - 1; //avail은 다음칸을 가리키고 있으므로 한칸 전으로 인덱스 설정
}
void print_info(polynomial* D) {

	for (int i = D->start; i < (D->finish) + 1; i++) {
		printf("coefficient of D : %f\n", terms[i].coef);
		printf("exponent of D : %d\n", terms[i].expon);
	}
}