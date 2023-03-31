#include <stdio.h>
int recursive_ackermann(int m, int n) {
	if (!m)
		return n + 1;
	else if (!n)
		recursive_ackermann(m - 1, 1);
	else
		recursive_ackermann(m - 1, recursive_ackermann(m, n - 1));
}
#include <stdio.h>


int loop_ackermann(int m, int n) {
    int stack[1000], top = -1;

    while (1) {
        if (m == 0) {
            if (top == -1) {
                return n + 1;
            }
            m = stack[top--];
            n += 1;
        }
        else if (n == 0) {
            n = 1;
            m--;
        }
        else {
            stack[++top] = m - 1;
            n--;
        }
    }
}


int main(int argc, char* argv[]) {
	int m,n;
	scanf_s("%d %d", &m, &n);
	printf("%d", loop_ackermann(m, n));
}