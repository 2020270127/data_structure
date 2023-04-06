#include <stdio.h>
#include <stdlib.h>
int main() {
	int **x, count = 0;

	x = (int*)malloc(sizeof(*x) * 3); // *x는 int **x로 선언된 x의 *하나를 지워서, int *x로 계산한다.
	for (int i = 0; i < 3; i++) {
		x[i] = (int*)malloc(sizeof(**x)*5); //위와 같이 **를 지워서 int x로 계산함.
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			x[i][j] = count++;
		}
	}


	//x[3][5] = { {0,1,2,3,4},{5,6,7,8,9},{10,11,12,13,14} };

	printf("value of x \t == %p\n", x); //x의 주소
	printf("value of x[0] \t == %p\n", x[0]); //x[0] 의 주소 == x의 주소
	printf("value of x[0][0] == %d\n", x[0][0]); // 0

	printf("addr of x \t == %p\n", &x); //x의 주소
	printf("addr of x[0] \t == %p\n", &x[0]);//x[0] 의 주소 == x의 주소
	printf("addr of x[0][0] == %p\n", &x[0][0]);// x[0][0] 의 주소 == x[0] 의 주소 == x의 주소

	printf("size of x \t == %lu\n", sizeof(x)); // 이차원 배열의 총 크기 >> 3 x 5 x (sizeof int) 4 == 60
	printf("size of x[0] \t == %lu\n", sizeof(x[0])); //이차원 배열 중 첫번째 배열의 크기 >> 5 x (sizeof int)4 = 20 
	printf("size of x[0][0] == %lu\n", sizeof(x[0][0])); // sizeof int >> 4

	printf("%p %p %p\n", x[0],x[1],x[2]);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%p ", &x[i][j]); // 배열로 저장했으니 순서대로 저장공간에 들어가지 않을까?
		}
		printf("\n");
	}
	
}