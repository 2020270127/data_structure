#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_ARR_SIZE 100 
int** powerset(int** arr, int size)
{

}
int main(int argc, char* argv[]) {
	char set[MAX_ARR_SIZE];
	int number_of_elements;
	printf("Input number of elements\n");
	scanf_s("%d", &number_of_elements);
	
	for (int i = 0; i < number_of_elements; i++) {
		scanf(" %c", set + i);
	}
	return 0;
}