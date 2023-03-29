#include <stdio.h>
#include <stdlib.h>
void printBooleans(int n, int* arr, int idx) {
    

    if (idx == n) { // ���� ����: ��� ������ ���� ���� ������ ���
        printf("< ");
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1)
                printf("true ");
            else
                printf("false ");// ���� boolean �������� ���� ���
        }
        printf(">\n");
        return;
    }
    // ���� ������ ���� true�� false�� ���� ���� �����ϸ鼭 ���� ������ �̵�
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
