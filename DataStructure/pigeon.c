/*임의의 함수 f
x: 입력 0 ~ 100

f(x) = f(y)인 값을 찾으면 반환
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
				random_num = rand() % 100; //임의의 정의역 하나 생성
				for (int i = 0; i < count; i++) {
					if (domain[i] == random_num) { //정의역에 해당 원소가 이미 있을때
						goto start;//다시 생성
					}
				}
				domain[count] = random_num;
				count++;//생성한 정의역 개수 기록
			}

			for (int i = 0; i < MAX; i++) {
				range[i] = FUNC(domain[i]);
			} // 공역 값 할당

			for (int i = 0; i < MAX; i++) {
				for (int j = i; j < MAX; j++) {
					if (range[i] == range[j] && i != j) {
						printf("a = %d, b = %d\n", domain[i], domain[j]);
						goto END; //하나만 찾을때
					}
				}
			}
			//return 0; //모두 찾을때
			printf("No answers...\n");
		END:;

}