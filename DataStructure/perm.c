#include <stdio.h>
#define SWAP(x,y,t)((t) = (x),(x) = (y),(y) = (t))
//모든 순서의 경우
int count = 0;
void perm(char* arr, int i, int n) {
	int j, temp;
	for (j = i; j < n; j++) {
		SWAP(arr[i], arr[j], temp);
		perm(arr, i + 1, n );
		SWAP(arr[i], arr[j], temp);
	}
	if (i == n-1) {
		for (int k = 0; k < n; k++) {
			printf("%c ",arr[k]);
		}
		printf("\n");
		count++;
	}
}

int main() {
	char arr[5] = { 'a','b','c','d','e'};
	perm(arr, 0, 5);
	printf("%d", count);
}