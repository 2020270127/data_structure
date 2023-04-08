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
