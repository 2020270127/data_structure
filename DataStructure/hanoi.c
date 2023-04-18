#include <stdio.h>
void hanoi(int n, int from, int by, int to);
void move(int from, int to);
int count = 0;
int main() {
    hanoi(4, 1, 2, 3);
    printf("count : %d", count);
}
void hanoi(int n, int from, int by, int to) {
    if (n == 1) move(from, to);
    else {
        hanoi(n - 1, from, to, by);
        move(from, to);
        hanoi(n - 1, by, from, to);
    }
}
void move(int from, int to) {
    printf("������ %d��° ��տ��� %d��° ������� �ű⼼��\n", from, to);
    count++;
}