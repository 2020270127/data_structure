#include <stdio.h>
#define FALSE 0
#define TRUE 1

typedef struct _sexType {
	enum tagField { female, male, idonknow, youknow, hihi } sex; //enum은 정수로 저장되므로 대부분의 컴파일러에서 4바이트로 정의된다.
	union _u {
		int children; //4바이트
		int beard;//4바이트 >> 가장 큰 값인 4바이트를 children,beard가 공유함
		//메모리를 공유하기 때문에 멤버별 둘 중 하나만 사용하는게 마땅함. 둘 다 사용할시 메모리 침범 가능성
	} u;
} sexType;
typedef struct _humanBeing {
	char name[10]; //10바이트
	int age; //4바이트
	float salary; // 4바이트
	int date_of_birth; // 4바이트
	sexType sexInfo;
} humanBeing;
humanBeing person1, person2;


int main() {
	person1.sexInfo.sex = male;
	person1.sexInfo.u.beard = FALSE;
	person1.sexInfo.u.children = 3;
	person2.sexInfo.sex = female;
	person2.sexInfo.u.children = 4;
	printf("size of union : %d", sizeof(person1));
}