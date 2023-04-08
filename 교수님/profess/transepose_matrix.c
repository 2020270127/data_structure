#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _matrix {
	int rows;
	int cols;
	int** e;
} matrix;


void mtranspose(matrix a, matrix *b) { //2차원 배열을 하나하나  transpose
	assert(b != NULL);
	assert((a.rows > 0) && (a.cols > 0));

	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			b->e[j][i] = a.e[i][j]; //b행렬의 값에 a행렬 값을 transpose해서 대입
		}
	}

}
int main() {

	matrix a,b;
	a.rows = 3; a.cols = 3; b.rows = 3; b.cols = 3;
	a.e = malloc(sizeof(int*) * a.rows);
	for (int i = 0; i < a.rows; i++) {
		a.e[i] = malloc(sizeof(int) * a.cols);
	}
	a.e[0][0] = 1; a.e[0][1] = 2; a.e[0][2] = 3;
	a.e[1][0] = 4; a.e[1][1] = 5; a.e[1][2] = 6;
	a.e[2][0] = 7; a.e[2][1] = 8; a.e[2][2] = 9;

	b.e = malloc(sizeof(int*) * b.rows);
	for (int i = 0; i < b.rows; i++) {
		b.e[i] = malloc(sizeof(int) * b.cols);
	}

	mtranspose(a, &b);

	for (int i = 0; i < b.rows; i++) {
		for (int j = 0; j < b.cols; j++) { // time complexity O(rows * cols)
			printf("%d ", b.e[i][j]);
		}
		printf("\n");
	}

	/*
	A = 1 2 3
	    4 5 6
		7 8 9
	*/

	/*
	output
	B =	1 4 7
		2 5 8
		3 6 9
	*/

}
