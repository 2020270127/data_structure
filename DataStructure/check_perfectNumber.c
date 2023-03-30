#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check_perfectNumber(int n) {/**본인의 제수의 합이 본인이 되는지 확인하는 함수*/
	int* arr;
	arr = (int*)malloc(sizeof(int) * n);
	//memset(arr, 0, sizeof(arr));//처음에 이렇게 적었는데, 이는 배열의 크기가 아닌 포인터 변수의 크기를 가져오므로 올바르지 않다.
	memset(arr, 0, sizeof(int) * n);


	int index = 0; //제수의 스택값, 하나 찾을때 마다 하나씩 증가
	int count = 0; //제수의 총 합을 저장하는 공간
	for (int i = 1; i < n; i++)//본인 자신은 제수가 아니라 n은 제외
	{
		if (n % i == 0) {
			arr[index] = i;
			index++;
		}
	}
	for (int i = 0; i < n; i++) {
		count += arr[i];
	}

	if (count == n)
		return 1;
	else
		return 0;
}

int main() {
	int input;
	int arr[5] = { 0 };
	int n = 5;
	printf("수를 입력하세요\n");
	scanf_s("%d", &input);
	if (check_perfectNumber(input))
		printf("완전수 입니다.\n");
	else
		printf("완전수가 아닙니다.\n");

}