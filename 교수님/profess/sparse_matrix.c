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
	assert(b[0].row * b[0].col >= a[0].value);//malloc�� �ƴ��� Ȯ��

	int numTerms, currentb;
	numTerms = a[0].value;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = numTerms; 

	if (numTerms > 0) {
		currentb = 1;
		for (int i = 0; i < a[0].col; i++) {//col �������� ����(Transpose�� ����� ����), a[0].col�� ��ü ���� ��
			//��� a�� ���� �������� ������ ����̹Ƿ� ���� ������� ���ĵǾ����� �ʴ�.
			//�׷��� 2�� for������ i��° ���� Ž���Ѵ�.
			//j�� a�� �ε���, i�� b�� �ε���. i+1�� currentb������, �׷��� ������ �������� �ſ� ������ 
			for (int j = 0; j <= numTerms; j++) {
				if (a[j].col == i) {//�ش� ���� ���ʰ� �ȴٸ�
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row; //transpose
					b[currentb].value = a[j].value;//���� ����
					currentb++;//���� ���ʷ�
				}
			}
		}
	}
}

void smfasttranspose(smatrix a, smatrix b) {
	assert((a != NULL) && (b != NULL));
	assert(b[0].row * b[0].col >= a[0].value);//malloc�� �ƴ��� Ȯ��

	unsigned int rowTerms[MAX_COLS], startingPos[MAX_COLS];
	int numTerms, currentb;
	numTerms = a[0].value;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = numTerms;

	if (numTerms > 0) {
		for (int i = 0; i < b[0].row; i++)//a�� ��
			rowTerms[i] = 0;

		for (int i = 1; i <= numTerms; i++)
			rowTerms[a[i].col]++; //��,���� ������ ��Ƽ� ���°� �ƴ϶�, �־��� ���� ����(A�� ��)��� col���� ����ִ� ���� count�Ѵ�. 
		//��������ǥ�� ����

		startingPos[0] = 1; //��ü �迭�� �Ӽ��� ��� �ִ� �迭�� 0��° �ε������� �����ؼ� ���������� 1�� ����
		for (int i = 1; i < b[0].row; i++) 
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1]; //A matrix�� ���� �������� ���������� ����, ���� ���� ������ ���� �κ�

		for (int i = 1; i <= numTerms; i++) {
			int j = startingPos[a[i].col]++; //���� ������ �ε����� ���, ++�� �ִ� ������ ������ a.col�� �� �� �ٸ� �ε��� ���� �����ϱ� ����
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
			/*
			startingPos[0] = 1  b[1],b[2] >> ���� 0
			startingPos[1] = 3  b[3]	  >> ���� 1
			startingPos[2] = 4  b[4],b[5] >> ���� 2
			startingPos[3] = 6  b[6]	  >> ���� 3
			startingPos[4] = 6  b[6]	  >> ���� 4
			startingPos[5] = 7  b[7]	  >> ���� 5
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
	assert(a[0].col == b[0].row); //��İ� ���� ����
	assert(a[0].col > 0);// �� a�� Ȯ������..?

	int rowBegin = 1, row = a[1].row, totalD = 0, sum = 0;
	int rowsA = a[0].row, colsA = a[0].col, totalA = a[0].value;
	int					  colsB = b[0].col, totalB = b[0].value;//����ȭ

	smatrix newA, newB;
	int capacity = smcreate(&newA, totalA + 2, 1);//ù��° �࿡�� ��Ŀ� ���� ����, ������ �࿡�� ���� ����. �׷��� +2
	//capacity�� ������ ����� ũ�⸦ ��ȯ
	assert(capacity >= totalA + 2);
	memcpy(newA, a, (totalA + 1) * sizeof(element)); //newA�� �޸𸮿� a�޸� ������ ����

	capacity = smcreate(&newB, totalB + 2, 1);//ù��° �࿡�� ��Ŀ� ���� ����, ������ �࿡�� ���� ����. �׷��� +2
	assert(capacity >= totalB + 2);
	smfasttranspose(b, newB); //newB �� b�� transpose
	
	newA[totalA + 1].row = rowsA;//������ ���� �� ����
	newB[totalB + 1].row = colsB;
	newB[totalB + 1].col = 0;

	for (int i = rowBegin; i <= totalA;) { // ��� A���� ������ŭ �ݺ�
		int column = newB[1].row; //������ ���� �̹� A�� ���̶� ����, ���� B�� ����. �࿭���̴ϱ�
		for (int j = 1; j <= totalB + 1;) { //��� B���� +1 ����ŭ �ݺ�
			if (newA[i].row != row) {
				storeSum(d, &totalD, row, column, &sum);//sum�� i,j�� ��ġ�Ҷ� ��İ� �տ��� ���� �ϳ�, totalD�� ������ sum�� ��(ȣ��ɶ����� +1)
														//matrix d�� totalD��° �ε����� row, column, sum���� ������. sum���� 0���� �ʱ�ȭ�ϱ� ���� �ּҷ� ����
				i = rowBegin;
				for (; newB[j].row == column; j++);//���� b ����??
				column = newB[j].row; //���� switch case���� i,j���� �Ű�µ� ĭ�� �����ִ� �۾�. �� for�� �ۿ��� rowBegin, row���� �������ش�. 
			}
			else if (newB[j].row != column) {
				storeSum(d, &totalD, row, column, &sum);
				i = rowBegin;
				column = newB[j].row;
			}  //������ �࿡ ���� ĭ�� ����� ���� ���� ���� ĭ�� �����.


			else switch (COMPARE(newA[i].col, newB[j].col)) {
			case -1: i++; break;
			case 0: 
				sum += newA[i++].value * newB[j++].value;
				break;
			case 1: j++;//�̰� ��� ����? polynomial������ ���׽��� ���� ������ ����ϳ�
			}

		}/* end of for j <= totalB+1 */

		for (; a[i].row == row; i++);//���� a����
		rowBegin = i; row = a[i].row;
	}/* end of for i <= totalA */
	d[0].row = rowsA; d[0].col = colsB; d[0].value = totalD;
}

int main() {
	smatrix a = malloc(sizeof(element)*9);
	a[0].row = 6;//��ü �迭�� row���� 
	a[0].col = 6;//��ü �迭�� col����
	a[0].value = 8;//��ü �迭 �� 0�� �ƴ� ���� ����
	a[1].row = 0; a[1].col = 0; a[1].value = 15; //���� �ִ� �迭 ����
	a[2].row = 0; a[2].col = 3; a[2].value = 22;
	a[3].row = 0; a[3].col = 5; a[3].value = -15;
	a[4].row = 1; a[4].col = 1; a[4].value = 11;
	a[5].row = 1; a[5].col = 2; a[5].value = 3;
	a[6].row = 2; a[6].col = 3; a[6].value = -6;
	a[7].row = 4; a[7].col = 0; a[7].value = 91;
	a[8].row = 5; a[8].col = 2; a[8].value = 28;

	smatrix b = malloc(sizeof(element) * 9);
	b[0].row = 6;//��ü �迭�� row���� 
	b[0].col = 6;//��ü �迭�� col����
	b[0].value = 8;//��ü �迭 �� 0�� �ƴ� ���� ����
	b[1].row = 1; b[1].col = 1; b[1].value = 15; //���� �ִ� �迭 ����
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
	d[0].row = 6;//��ü �迭�� row���� 
	d[0].col = 6;//��ü �迭�� col����
	d[0].value = 8;//��ü �迭 �� 0�� �ƴ� ���� ����
	
	}
