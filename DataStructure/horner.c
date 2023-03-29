#include <stdio.h>

int a[5] = { 5,4,3,2,1 };

int horner(int k);
int main() {
	printf("%d", horner(1));
}
int horner(int k) {
	int f = a[0];
	for (int i = 1; i < 5; i++) {
		f = f * k + a[i]; //recursive
	}
	return f;
}