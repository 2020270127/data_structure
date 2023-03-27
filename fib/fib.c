#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, c, i;
    printf("%d ", a);
    printf("%d ", b);

    for (i = 2; i < n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}
