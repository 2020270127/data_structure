
//struct personal_info {
	//	char name[10];
	//	int age;
	//	float salary;
	//};//구조체 정의
	//struct personal_info person;//변수 생성

	//typedef struct personal_info1 {
	//	char name[10];
	//	int age;
	//	float salary;
	//	struct personal_info1* a; //자기참조
	//} person1;//typedef 'struct' as 'person'

	//strcpy(person.name, "lee");
	//person.age = 10;
	//person.salary = 35000;

#include <stdio.h>
#include <stdbool.h>
int main() {
	typedef struct _sexType {
		enum tagField { female, male } sex;
		union _u {
			int children;
			bool beard;
		} u;
	} sexType;

	typedef struct _humanBeing {
		char name[10];
		int age;
		float salary;
		sexType sexInfo;
	} humanBeing;
	humanBeing person1, person2;

	person1.sexInfo.sex = male;
	person1.sexInfo.u.beard = 0;
	person2.sexInfo.sex = female;
	person2.sexInfo.u.children = 4;
}