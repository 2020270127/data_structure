#include <stdio.h>
#define FALSE 0
#define TRUE 1

typedef struct _sexType {
	enum tagField { female, male, idonknow, youknow, hihi } sex; //enum�� ������ ����ǹǷ� ��κ��� �����Ϸ����� 4����Ʈ�� ���ǵȴ�.
	union _u {
		int children; //4����Ʈ
		int beard;//4����Ʈ >> ���� ū ���� 4����Ʈ�� children,beard�� ������
		//�޸𸮸� �����ϱ� ������ ����� �� �� �ϳ��� ����ϴ°� ������. �� �� ����ҽ� �޸� ħ�� ���ɼ�
	} u;
} sexType;
typedef struct _humanBeing {
	char name[10]; //10����Ʈ
	int age; //4����Ʈ
	float salary; // 4����Ʈ
	int date_of_birth; // 4����Ʈ
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