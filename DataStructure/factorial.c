#include <stdio.h>
#include <stdlib.h>
int recursive_factorial(int n, int result) {
	result *= n;
	if (n == 1)
		return result;
	recursive_factorial(n - 1,result);
}/**재귀함수에 무한 루프를 사용하면, 재귀하는 만큼 무한루프가 겹친다.*/
int loop_factorial(int n, int result) {
	while (n > 0) {
		result *= n;
		n--;
	}
	return result;
}

int main() {
	int input, result = 1;
	scanf_s("%d", &input);
	if (input == 0) {
		printf("1\n");
	}
	else if (input < 0) {
		printf("음수의 계승은 정의되지 않았습니다.\n");
	}
	else {
		printf("recursive : %d\n", recursive_factorial(input, result));
		printf("loop : %d", loop_factorial(input, result));
	}

	printf("size of factorial : %d", sizeof(recursive_factorial));
}