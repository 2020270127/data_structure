#include <stdio.h>
int recursive_binomial_coefficient(int n, int r, int temp)
{
	if (r == 1) {
		temp += n;
		return temp;
	}
	else if (n == r) {
		temp++;
		return temp;
	}
	else if (n < r) {
		printf("r can't be larger than n\n");
		return -1;
	}
	temp = recursive_binomial_coefficient(n - 1, r, temp) + recursive_binomial_coefficient(n - 1, r - 1, temp);
}
int loop_binomial_coefficient(int n, int r) {//해당 함수는 입력값에 따라 변수의 overflow 가능성이 있습니다.
	int result = 0;
	if (n > r) {
		long long denominator = 1, numerator1 = 1, numerator2 = 1;
		for (int i = 1; i <= n; i++) {
			denominator *= i;
		}
		for (int i = 1; i <= r; i++) {
			numerator1 *= i;
		}
		for (int i = 1; i <= n - r; i++) {
			numerator2 *= i;
		}
		result = denominator / (numerator1 * numerator2);
	}
	else if (n == r) {
		result = 1;
	}
	else
		return -1;

	return result;
	
	
}
int main() {
	int n,r,temp = 0; 
	printf("intput n, r\n");
	scanf_s("%d %d", &n, &r);
	if (recursive_binomial_coefficient != -1)
	{
		printf("(recursive)%d Combination %d : %d\n", n, r, recursive_binomial_coefficient(n, r, temp));
		printf("(loop)%d Combination %d : %d\n", n, r, loop_binomial_coefficient(n, r));
	}

	else
		printf("Error\n");
}