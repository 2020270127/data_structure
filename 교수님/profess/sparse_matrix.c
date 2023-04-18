#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define COMPARE(x,y)(((x)>(y))?1:((x)==(y))? 0:1)
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_ELEMENTS 	101 /* maximum number of terms + 1 */
#define MAX_COLS		100
#define MAX_ROWS		MAX_COLS
/*
 15  0 0 22 0 -15
 0  11 3 0  0  0
 0  0  0 -6 0  0
 0  0  0  0 0  0
 91 0  0  0 0  0
 0  0 28  0 0  0
*/

///////////////////////////copied code////////////////////////////////////////////
unsigned int smcreate(smatrix* a, const unsigned int rows, const unsigned int cols) {
	assert(a != NULL);

	unsigned int capacity = MIN(rows * cols, MAX_ELEMENTS);
	*a = malloc(capacity * sizeof(element));
	(*a)[0].row = rows;
	(*a)[0].col = cols;
	(*a)[0].value = 0; // zero matrix
	return capacity;
}
void storeSum(smatrix d, int* totalD, int row, int column, int* sum) {
	/* if *sum != 0, then it along with its row and column
	   position is stored as the *totalD+1 entry in d */
	if (*sum) {
		assert(*totalD < MAX_ELEMENTS - 1);
		/* printf("%d \n", *totalD); */
		d[++ * totalD].row = row;
		d[*totalD].col = column;
		d[*totalD].value = *sum;
		*sum = 0;
	}
}
////////////////////////////////////////////////////////////////////////////////

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

void smmultiply(smatrix a, smatrix b, smatrix d) {
	assert((a != NULL) && (b != NULL) && (d != NULL));
	assert(a[0].col == b[0].row); //행렬곱 성립 조건
	assert(a[0].col > 0);// 왜 a만 확인하지..?

	int rowBegin = 1, row = a[1].row, totalD = 0, sum = 0;
	int rowsA = a[0].row, colsA = a[0].col, totalA = a[0].value;
	int					  colsB = b[0].col, totalB = b[0].value;//가시화

	smatrix newA, newB;
	int capacity = smcreate(&newA, totalA + 2, 1);//첫번째 행에는 행렬에 대한 정보, 마지막 행에는 종료 조건. 그래서 +2
	//capacity는 생성된 행렬의 크기를 반환
	assert(capacity >= totalA + 2);
	memcpy(newA, a, (totalA + 1) * sizeof(element)); //newA의 메모리에 a메모리 내용을 복붙

	capacity = smcreate(&newB, totalB + 2, 1);//첫번째 행에는 행렬에 대한 정보, 마지막 행에는 종료 조건. 그래서 +2
	assert(capacity >= totalB + 2);
	smfasttranspose(b, newB); //newB 는 b의 transpose
	
	newA[totalA + 1].row = rowsA;//마지막 행의 값 설정
	newB[totalB + 1].row = colsB;
	newB[totalB + 1].col = 0;

	for (int i = rowBegin; i <= totalA;) { // 행렬 A원소 개수만큼 반복
		int column = newB[1].row; //위에서 행은 이미 A의 행이라 선언, 열은 B의 열임. 행열곱이니깐
		for (int j = 1; j <= totalB + 1;) { //행렬 B원소 +1 수만큼 반복
			if (newA[i].row != row) {
				storeSum(d, &totalD, row, column, &sum);//sum은 i,j가 일치할때 행렬곱 합원소 중의 하나, totalD는 생성된 sum값 수(호출될때마다 +1)
														//matrix d의 totalD번째 인덱스에 row, column, sum값을 대입함. sum값은 0으로 초기화하기 위해 주소로 전달
				i = rowBegin;
				for (; newB[j].row == column; j++);//남은 b 원소??
				column = newB[j].row; //밑의 switch case에서 i,j값을 옮겼는데 칸을 맞춰주는 작업. 이 for문 밖에서 rowBegin, row값을 수정해준다. 
			}
			else if (newB[j].row != column) {
				storeSum(d, &totalD, row, column, &sum);
				i = rowBegin;
				column = newB[j].row;
			}  //위에선 행에 대한 칸을 맞췄고 이젠 열에 대한 칸을 맞춘다.


			else switch (COMPARE(newA[i].col, newB[j].col)) {
			case -1: i++; break;
			case 0: 
				sum += newA[i++].value * newB[j++].value;
				break;
			case 1: j++;//이거 어디서 봤지? polynomial에서의 다항식의 덧셈 구현과 비슷하네
			}

		}/* end of for j <= totalB+1 */

		for (; a[i].row == row; i++);//남은 a원소
		rowBegin = i; row = a[i].row;
	}/* end of for i <= totalA */
	d[0].row = rowsA; d[0].col = colsB; d[0].value = totalD;
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
