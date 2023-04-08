#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
 15  0 0 22 0 -15
 0  11 3 0  0  0
 0  0  0 -6 0  0
 0  0  0  0 0  0
 91 0  0  0 0  0
 0  0 28  0 0  0
*/
#define MAX_ELEMENTS 101
typedef struct _elements {
	int row;
	int col;
	int value;
} element;
typedef element* smatrix;




int main() {
	smatrix a = malloc(sizeof(element)*9);
	a[0].row = 6;//전체 배열의 row개수 
	a[0].col = 6;//전체 배열의 col개수
	a[0].value = 8;//전체 배열 중 0이 아는 값의 개수
	a[1].row = 1; a[1].col = 1; a[1].value = 15; //값이 있는 배열 대입
	a[2].row = 1; a[2].col = 4; a[2].value = 22;
	a[3].row = 1; a[3].col = 6; a[3].value = -15;
	a[4].row = 2; a[4].col = 2; a[4].value = 11;
	a[5].row = 2; a[5].col = 3; a[5].value = 3;
	a[6].row = 3; a[6].col = 4; a[6].value = -6;
	a[7].row = 5; a[7].col = 1; a[7].value = 91;
	a[8].row = 6; a[8].col = 3; a[8].value = 28;

	}
