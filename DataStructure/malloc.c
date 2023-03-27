#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s)\
	if(!( (p)=malloc(s) )){\
	fprintf(stderr, "Insufficient memory");\
	exit(EXIT_FAILURE);\
	}
void main() {
	int i, * pi;
	float f, * pf;
	pi = (int*)malloc(sizeof(int));
	MALLOC(pi, sizeof(int));
	MALLOC(pf, sizeof(float));
	pf = (float*)malloc(sizeof(float));
	*pi = 1024;
	*pf = 3.14;
	printf("an integer = %d, a float = %f\n", *pi, *pf);
	free(pi);
	free(pf);
}
 