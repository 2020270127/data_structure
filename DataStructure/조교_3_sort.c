#include <stdio.h>
#define swap(a, b) {int tmp=a; a=b; b=tmp;}

void select_swap(int* arr) {
	int min = arr[0];
	for (int i = 0; i < 2; i++) {
		int min_index = i;
		for (int j = i + 1; j < 3; j++) {
			if (arr[j] < arr[min_index])
				min_index = j;
		}
		swap(arr[i], arr[min_index]);
	}
}
void insert_swap(int* arr) {

	for (int i = 1; i < 3; i++) {
		int insult_num = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > insult_num) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = insult_num;
	}
}
void shellSort(int* arr) {
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
//binsearch ±¸Çö
int main() {
	int arr[3] = { 0, };

	scanf_s("%d %d %d", &arr[0], &arr[1], &arr[2]);

	//select_swap(arr);
	//insert_swap(arr);
	shellSort(arr);
	for (int i = 0; i < 3; i++)
		printf("%d ", arr[i]);


}