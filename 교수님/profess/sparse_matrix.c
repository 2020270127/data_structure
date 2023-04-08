#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_COLS 101
#define MAX_ROWS 101
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

void smtranspose(smatrix a, smatrix b) {
	assert((a != NULL) && (b != NULL));
	assert(b[0].row * b[0].col >= a[0].value);//malloc잘 됐는지 확인

	int numTerms, currentb;
	numTerms = a[0].value;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = numTerms; 

	if (numTerms > 0) {
		currentb = 1;
		for (int i = 0; i < a[0].col; i++) {//col 관점으로 시작(Transpose된 행렬의 입장), a[0].col은 전체 열의 수
			//행렬 a는 행을 기준으로 정렬한 행렬이므로 열의 순서대로 정렬되어있지 않다.
			//그래서 2중 for문으로 i번째 열을 탐색한다.
			//j는 a의 인덱스, i는 b의 인덱스. i+1이 currentb이지만, 그렇게 적으면 가독성이 매우 떨어짐 
			for (int j = 0; j <= numTerms; j++) {
				if (a[j].col == i) {//해당 열의 차례가 된다면
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row; //transpose
					b[currentb].value = a[j].value;//값은 같음
					currentb++;//다음 차례로
				}
			}
		}
	}
}

void smfasttranspose(smatrix a, smatrix b) {
	assert((a != NULL) && (b != NULL));
	assert(b[0].row * b[0].col >= a[0].value);//malloc잘 됐는지 확인

	unsigned int rowTerms[MAX_COLS], startingPos[MAX_COLS];
	int numTerms, currentb;
	numTerms = a[0].value;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = numTerms;

	if (numTerms > 0) {
		for (int i = 0; i < b[0].row; i++)//a의 행
			rowTerms[i] = 0;

		for (int i = 1; i <= numTerms; i++)
			rowTerms[a[i].col]++; //행,열을 기준을 잡아서 보는게 아니라, 주어진 행의 순서(A의 행)대로 col값에 들어있는 값을 count한다. 
		//도수분포표를 생각

		startingPos[0] = 1; //전체 배열의 속성을 담고 있는 배열의 0번째 인덱스값을 생각해서 누적도수는 1로 시작
		for (int i = 1; i < b[0].row; i++) 
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1]; //A matrix의 행을 기준으로 누적도수를 구함, 그저 누적 도수를 위한 부분

		for (int i = 1; i <= numTerms; i++) {
			int j = startingPos[a[i].col]++; //누적 도수로 인덱스를 계산, ++가 있는 이유는 동일한 a.col로 갈 때 다른 인덱스 값을 지정하기 위함
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
			/*
			startingPos[0] = 1  b[1],b[2] >> 열이 0
			startingPos[1] = 3  b[3]	  >> 열이 1
			startingPos[2] = 4  b[4],b[5] >> 열이 2
			startingPos[3] = 6  b[6]	  >> 열이 3
			startingPos[4] = 6  b[6]	  >> 열이 4
			startingPos[5] = 7  b[7]	  >> 열이 5
			*/
		}
	}
}

void print_array(smatrix a, int num) {
	for (int i = 0; i < num; i++) {
			printf("<%d %d %d>", a[i].row, a[i].col, a[i].value);
			printf("\n");
	}
	printf("\n");
}
void smadd(smatrix a, smatrix b, smatrix* d) {

}

int main() {
	smatrix a = malloc(sizeof(element)*9);
	a[0].row = 6;//전체 배열의 row개수 
	a[0].col = 6;//전체 배열의 col개수
	a[0].value = 8;//전체 배열 중 0이 아는 값의 개수
	a[1].row = 0; a[1].col = 0; a[1].value = 15; //값이 있는 배열 대입
	a[2].row = 0; a[2].col = 3; a[2].value = 22;
	a[3].row = 0; a[3].col = 5; a[3].value = -15;
	a[4].row = 1; a[4].col = 1; a[4].value = 11;
	a[5].row = 1; a[5].col = 2; a[5].value = 3;
	a[6].row = 2; a[6].col = 3; a[6].value = -6;
	a[7].row = 4; a[7].col = 0; a[7].value = 91;
	a[8].row = 5; a[8].col = 2; a[8].value = 28;

	smatrix b = malloc(sizeof(element) * 9);
	b[0].row = 6;//전체 배열의 row개수 
	b[0].col = 6;//전체 배열의 col개수
	b[0].value = 8;//전체 배열 중 0이 아는 값의 개수
	b[1].row = 1; b[1].col = 1; b[1].value = 15; //값이 있는 배열 대입
	b[2].row = 1; b[2].col = 4; b[2].value = 22;
	b[3].row = 1; b[3].col = 6; b[3].value = -15;
	b[4].row = 2; b[4].col = 2; b[4].value = 11;
	b[5].row = 2; b[5].col = 3; b[5].value = 3;
	b[6].row = 3; b[6].col = 4; b[6].value = -6;
	b[7].row = 5; b[7].col = 1; b[7].value = 91;
	b[8].row = 6; b[8].col = 3; b[8].value = 28;
	smtranspose(a, b);
	print_array(a,9);
	print_array(b,9);

	smatrix d = malloc(sizeof(element) * 9);
	d[0].row = 6;//전체 배열의 row개수 
	d[0].col = 6;//전체 배열의 col개수
	d[0].value = 8;//전체 배열 중 0이 아는 값의 개수
	
	}
