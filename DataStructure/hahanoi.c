#include <stdio.h>
#define bar(a) bar_a
void hanoi(int numberof_plate, int from, int by, int to);
void move(int from, int to);
int count = 0;
int main() {
    hanoi(5, 1, 2, 3);
    printf("count : %d", count);
}
void hanoi(int numberof_plate, int bar1, int bar2, int bar3) {
    if (numberof_plate == 1) move(numberof_plate, bar1, bar3);
    else {
        hanoi(numberof_plate - 1, bar1, bar3, bar2);
        move(numberof_plate, bar1, bar3);
        hanoi(numberof_plate - 1, bar2, bar1, bar3);
    }
}
void move(int numberof_plate, int from, int to) {
    printf("%d 원반을 %d번째 기둥에서 %d번째 기둥으로 옮기세요\n", numberof_plate, from, to);
    count++;
}