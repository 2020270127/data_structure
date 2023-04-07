#include <stdio.h>
#define MAX_SIZE 10
int count = 0;
float sum(float list[], int n) {
	float tempsum = 0; //변수에 대입할때,1
	int i;//선언할때는 countX
	for (i = 0; i < n; i++) { // i++, tempsum대입을 총 n번, 2xn (첫 for문에선 i++이 아닌 i = 0에서 count 발생)
		tempsum += list[i];
	}//마지막 i++, 1
	return tempsum; //리턴할때, 1
} //총 2n + 3

void add(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rows, int cols) {
	int i, j; //변수 선언, count 0
	for (i = 0; i < rows; i++) //변수 수정, count 1 , rows + 1번 (마지막 조건이 충족되지 않아 나갈때도 i++)
		for (j = 0; j < cols; j++)//변수 수정, count 1, rows * (cols + 1)번
			c[i][j] = a[i][j] + b[i][j];//변수 수정, count 1, rows*cols 번
}								//총 rc + rc + r + r + 1번 >>  2rc + 2r + 1번