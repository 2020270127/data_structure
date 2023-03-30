#include <stdio.h>
#include <stdlib.h>
int temp = 0;

int recursive_fibonacci(int n,int temp) {
	if (n == 1) {
		return 1;
	}
	else if (n == 0) {
		return 0;
	}
	else
		temp = recursive_fibonacci(n - 1,temp) + recursive_fibonacci(n - 2,temp);
}
int loop_fibonacci(int n) {
	int* arr;
	arr = (int*)malloc(sizeof(int) * (n+1));
	memset(arr, 0, sizeof(int) * (n+1));
	
	if (n > 1) // 만약 n이 1 이하일 경우, 메모리 침범
		arr[0] = 0, arr[1] = 1;  //index주의! 첫번째 피보나치, 두번째 피보나치 값은 각각 1. 
	else if (n == 0)
		return 0;
	else if (n == 1)
		return 1;

	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
}
int main() {
	int input;
	printf("input : ");
	scanf_s("%d", &input);
	if (input < 0)
		return -1;

	printf("recursive_fibonacci(%d) = %d\n", input, recursive_fibonacci(input, temp));
	printf("loop_fibonacci(%d) = %d\n",input, loop_fibonacci(input));
}