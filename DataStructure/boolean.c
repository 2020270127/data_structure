#include <stdio.h>
#include <stdlib.h>
void printBooleans(int n, int* arr, int idx) {
    

    if (idx == n) { // 기저 조건: 모든 변수에 대한 값을 설정한 경우
        printf("< ");
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1)
                printf("true ");
            else
                printf("false ");// 현재 boolean 변수들의 값을 출력
        }
        printf(">\n");
        return;
    }
    // 현재 변수에 대해 true와 false의 값을 각각 설정하면서 다음 변수로 이동
    arr[idx] = 1;
    printBooleans(n, arr, idx + 1);
    arr[idx] = 0;
    printBooleans(n, arr, idx + 1);
}

int main() {
    int n;
    scanf_s("%d", &n);
    int* arr;
    arr = (int*)(malloc(sizeof(int) * n));
    printBooleans(n, arr, 0);
    free(arr);
    return 0;
}
