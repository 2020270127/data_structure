#include <stdio.h>
int recursive_ackermann(int m, int n) {
	if (!m)
		return n + 1;
	else if (!n)
		recursive_ackermann(m - 1, 1);
	else
		recursive_ackermann(m - 1, recursive_ackermann(m, n - 1));
}

int loop_ackermann(int m, int n) {
    int stack[1000], top = 0, current = 0;
    stack[0] = m;

    while (top >= 0) {
        current = stack[top]; //현재 top이 가르키고 있는 값
        if (current == 0) // 그 값이 만약 0이라면
        {
            n++; // n을 n+1로 업데이트
            top--; //top를 한칸 뒤로 옮김
        }
        else if (n == 0) {
            n = 1;
            stack[top] = current - 1;
        }
        else{
            n--; //n을 n - 1로 업데이트
            stack[top] = current - 1; //지금 top칸을 m - 1로 업데이트
            stack[++top] = current; //그 다음 top칸을 m으로 업데이트
        }        
    }
    return n;
}

int main(int argc, char* argv[]) {
	int m,n;
	scanf_s("%d %d", &m, &n);
    printf("achkermann with recursive : %d\n", recursive_ackermann(m, n));
	printf("achkermann with loop : %d\n", loop_ackermann(m, n));
}