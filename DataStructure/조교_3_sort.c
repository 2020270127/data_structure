#include <stdio.h>
#include <stdlib.h>
#define swap(x,y,t)((t) = (x),(x) = (y),(y) = (t))

void select_swap_up(int* arr, int size) {// 오름차순
	int temp;
	for (int i = 0; i < size - 1; i++) { //최소값 지정 포인터
		int min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min_index])
				min_index = j;
		}
		swap(arr[i], arr[min_index],temp);
	}
}

void select_swap_down(int* arr, int size) { // 내림차순
	int temp;
	for (int i = 0; i < size - 1; i++) { //최댓값 지정 포인터
		int max_index = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[max_index] < arr[j])
				max_index = j;
		}
		swap(arr[max_index], arr[i], temp);
	}
}


void insert_swap(int* arr, int size) {

	for (int i = 1; i < size; i++) {
		int insult_num = arr[i];  //한개 빼두고
		int j = i - 1;
		while (j >= 0 && arr[j] > insult_num) {//대소 비교로 
			arr[j + 1] = arr[j];//오른쪽으로 복사
			j--;
		}
		arr[j+1] = insult_num;
	}
}
void shellSort(int* arr, int size) {
	int n = 3;
	int gap = 1;
	while (gap < n / 3)
		gap = 3 * gap + 1;
	while (gap >= 1) {
		for (int i = gap; i <= n - 1; i++) {
			int temp = arr[i];
			int j = i;
			while (j >= gap && arr[j - gap] > temp) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
		}
		gap = (gap - 1) / 3;
	}
}
//binsearch 구현
int main() {
	int *arr, size;
	printf("input size\n");
	scanf_s("%d", &size);

	arr = (int*)malloc(sizeof(int) * size);
	printf("\n");

	for (int i = 0; i < size; i++)
		scanf_s("%d", arr+i);

	insert_swap(arr, size);
		//shellSort(arr,size);
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);


}