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
				attach_to_new(coefficient, terms[A.start].expon); // A,B�� expon���� �����Ƿ� A,B�� � expon���� ���� ����
			A.start++;
			B.start++;
			break;
		case 1:
			attach_to_new(terms[A.start].coef, terms[A.start].expon);
			A.start++;
		}
	} //�ش� ������ �־��� �ð����⵵: (A ���� ����) + (B���� ����) - 1(�׻� ������ �ϳ��� ���ԵǱ� ���� ���� ����)
	for (; A.start <= A.finish; A.start++) 
		attach_to_new(terms[A.start].coef, terms[A.start].expon);
	for (; B.start <= B.finish; B.start++)
		attach_to_new(terms[B.start].coef, terms[B.start].expon);
	//�����ִ� �׵��� ó���ϴ� ����, �־��� �ð� ���⵵�� : (A���� ����) + (B���� ����)
	D->finish = avail - 1; //avail�� ����ĭ�� ����Ű�� �����Ƿ� ��ĭ ������ �ε��� ����
}
void print_info(polynomial* D) {

	for (int i = D->start; i < (D->finish) + 1; i++) {
		printf("coefficient of D : %f\n", terms[i].coef);
		printf("exponent of D : %d\n", terms[i].expon);
	}
}