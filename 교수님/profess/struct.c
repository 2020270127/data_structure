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
	struct personal_info { //����ü �̸� �ݵ�� ����! �ڱ������� ���� 
		char name[10];
		int age;
		float salary; //field
	} person; //personal_info��� ������ ���� ����(~��ü) person ����
	struct personal_info person1; //�̷��� personal_info��� ������ ���� �Ǵٸ� ����ü ���� ����

	typedef struct personal_info1 {
		char name[10];
		int age;
		float salary;
	} person_type; // ���⼭ person�� �����̸��� �ƴ�!! typedef B A > B�� A�� ������ �̶�� �������� ���� ���� ����ü�� �ǹ���
	person_type p; // p�� personal_info1�� ������ ���� ����(~��ü)



	omg.name = (char*)malloc(sizeof(char) * 10);
	homg.name = (char*)malloc(sizeof(char) * 10);

	strcpy(omg.name, "lee");
	omg.age = 23;
	omg.salary = 10000000;

	homg = omg; //�̷��� �����ͱ��� ����Ǽ� ���� �Ҵ�� homg�� �̸��� ����� ������ �����Ⱑ �ǰ�, omg name�� ����

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