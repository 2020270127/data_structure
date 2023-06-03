#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define FALSE 0
#define TRUE 1
typedef struct _humanBeing {
	char* name;
	int age;
	float salary;
	struct _humanBeing* a;
} humanBeing;
humanBeing omg, homg;

int humansEqual(humanBeing* person1, humanBeing* person2) {
	if (strcmp(person1->name, person2->name))
		return FALSE;
	if (person1->age != person2->age)
		return FALSE;
	if (person1->salary != person2->salary)
		return FALSE;
	return TRUE;

}
int main() {
	struct personal_info { //구조체 이름 반드시 기재! 자기참조를 위해 
		char name[10];
		int age;
		float salary; //field
	} person; //personal_info라는 구조를 가진 변수(~객체) person 생성
	struct personal_info person1; //이렇게 personal_info라는 구조를 가진 또다른 구조체 생성 가능

	typedef struct personal_info1 {
		char name[10];
		int age;
		float salary;
	} person_type; // 여기서 person은 변수이름이 아님!! typedef B A > B를 A라 정의함 이라는 문법으로 인해 위의 구조체를 의미함
	person_type p; // p는 personal_info1의 구조를 가진 변수(~객체)



	omg.name = (char*)malloc(sizeof(char) * 10);
	homg.name = (char*)malloc(sizeof(char) * 10);

	strcpy(omg.name, "lee");
	omg.age = 23;
	omg.salary = 10000000;

	homg = omg; //이러면 포인터까지 복사되서 원래 할당된 homg의 이름이 저장된 공간은 쓰레기가 되고, omg name을 따라감

	strcpy(homg.name, "hoo");
	homg.age = 32;
	homg.salary = 200;


	printf("omg name : %s\n", omg.name);
	printf("omg age : %d\n", omg.age);
	printf("omg name : %f\n", omg.salary);

	printf("homg name : %s\n", homg.name);
	printf("homg age : %d\n", homg.age);
	printf("homg name : %f\n", homg.salary);

}