#include <stdio.h>
#define MAX_SIZE 10
int count = 0;
float sum(float list[], int n) {
	float tempsum = 0; //������ �����Ҷ�,1
	int i;//�����Ҷ��� countX
	for (i = 0; i < n; i++) { // i++, tempsum������ �� n��, 2xn (ù for������ i++�� �ƴ� i = 0���� count �߻�)
		tempsum += list[i];
	}//������ i++, 1
	return tempsum; //�����Ҷ�, 1
} //�� 2n + 3

void add(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rows, int cols) {
	int i, j; //���� ����, count 0
	for (i = 0; i < rows; i++) //���� ����, count 1 , rows + 1�� (������ ������ �������� �ʾ� �������� i++)
		for (j = 0; j < cols; j++)//���� ����, count 1, rows * (cols + 1)��
			c[i][j] = a[i][j] + b[i][j];//���� ����, count 1, rows*cols ��
}								//�� rc + rc + r + r + 1�� >>  2rc + 2r + 1��