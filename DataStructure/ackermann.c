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
        current = stack[top]; //���� top�� ����Ű�� �ִ� ��
        if (current == 0) // �� ���� ���� 0�̶��
        {
            n++; // n�� n+1�� ������Ʈ
            top--; //top�� ��ĭ �ڷ� �ű�
        }
        else if (n == 0) {
            n = 1;
            stack[top] = current - 1;
        }
        else{
            n--; //n�� n - 1�� ������Ʈ
            stack[top] = current - 1; //���� topĭ�� m - 1�� ������Ʈ
            stack[++top] = current; //�� ���� topĭ�� m���� ������Ʈ
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