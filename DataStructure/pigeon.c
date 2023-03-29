/*������ �Լ� f
x: �Է� 0 ~ 100

f(x) = f(y)�� ���� ã���� ��ȯ
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define FUNC(x)(x*x - 100*x +8)
#define MAX 30
int main() {
	int random_num;
	int count = 0;
	srand(time(NULL));


	int domain[MAX] = {0};
	int range[MAX] = {0};


	start : while(count < MAX)
			{
				random_num = rand() % 100; //������ ���ǿ� �ϳ� ����
				for (int i = 0; i < count; i++) {
					if (domain[i] == random_num) { //���ǿ��� �ش� ���Ұ� �̹� ������
						goto start;//�ٽ� ����
					}
				}
				domain[count] = random_num;
				count++;//������ ���ǿ� ���� ���
			}

			for (int i = 0; i < MAX; i++) {
				range[i] = FUNC(domain[i]);
			} // ���� �� �Ҵ�

			for (int i = 0; i < MAX; i++) {
				for (int j = i; j < MAX; j++) {
					if (range[i] == range[j] && i != j) {
						printf("a = %d, b = %d\n", domain[i], domain[j]);
						goto END; //�ϳ��� ã����
					}
				}
			}
			//return 0; //��� ã����
			printf("No answers...\n");
		END:;

}