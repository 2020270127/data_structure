#include <stdio.h>
#include <stdlib.h>
int main() {
	int **x, count = 0;

	x = (int*)malloc(sizeof(*x) * 3); // *x�� int **x�� ����� x�� *�ϳ��� ������, int *x�� ����Ѵ�.
	for (int i = 0; i < 3; i++) {
		x[i] = (int*)malloc(sizeof(**x)*5); //���� ���� **�� ������ int x�� �����.
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			x[i][j] = count++;
		}
	}


	//x[3][5] = { {0,1,2,3,4},{5,6,7,8,9},{10,11,12,13,14} };

	printf("value of x \t == %p\n", x); //x�� �ּ�
	printf("value of x[0] \t == %p\n", x[0]); //x[0] �� �ּ� == x�� �ּ�
	printf("value of x[0][0] == %d\n", x[0][0]); // 0

	printf("addr of x \t == %p\n", &x); //x�� �ּ�
	printf("addr of x[0] \t == %p\n", &x[0]);//x[0] �� �ּ� == x�� �ּ�
	printf("addr of x[0][0] == %p\n", &x[0][0]);// x[0][0] �� �ּ� == x[0] �� �ּ� == x�� �ּ�

	printf("size of x \t == %lu\n", sizeof(x)); // ������ �迭�� �� ũ�� >> 3 x 5 x (sizeof int) 4 == 60
	printf("size of x[0] \t == %lu\n", sizeof(x[0])); //������ �迭 �� ù��° �迭�� ũ�� >> 5 x (sizeof int)4 = 20 
	printf("size of x[0][0] == %lu\n", sizeof(x[0][0])); // sizeof int >> 4

	printf("%p %p %p\n", x[0],x[1],x[2]);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%p ", &x[i][j]); // �迭�� ���������� ������� ��������� ���� ������?
		}
		printf("\n");
	}
	
}