#include <stdio.h>
#include <stdlib.h>
typedef struct person {
	int* age;
} person;

int main() {
	person a;
	a.age = malloc(sizeof(int) * 3);
	a.age[0] = 1;
	a.age[1] = 2;
	a.age[2] = 3;
	printf("%p\n", *(a.age+1));
}
