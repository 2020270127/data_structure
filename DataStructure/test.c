#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int n = 0;

START: 	for(;;)
	{

		printf("%s", "testing1.\n");
		for (;;) {
			printf("%s", "testing2.\n");
			scanf("%d", &n);
			if (n == 1)
				break START;

		}
	}
	
}