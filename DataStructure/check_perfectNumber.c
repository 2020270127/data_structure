#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check_perfectNumber(int n) {/**������ ������ ���� ������ �Ǵ��� Ȯ���ϴ� �Լ�*/
	int* arr;
	arr = (int*)malloc(sizeof(int) * n);
	//memset(arr, 0, sizeof(arr));//ó���� �̷��� �����µ�, �̴� �迭�� ũ�Ⱑ �ƴ� ������ ������ ũ�⸦ �������Ƿ� �ùٸ��� �ʴ�.
	memset(arr, 0, sizeof(int) * n);


	int index = 0; //������ ���ð�, �ϳ� ã���� ���� �ϳ��� ����
	int count = 0; //������ �� ���� �����ϴ� ����
	for (int i = 1; i < n; i++)//���� �ڽ��� ������ �ƴ϶� n�� ����
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
	printf("���� �Է��ϼ���\n");
	scanf_s("%d", &input);
	if (check_perfectNumber(input))
		printf("������ �Դϴ�.\n");
	else
		printf("�������� �ƴմϴ�.\n");

}