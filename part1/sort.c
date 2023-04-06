#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sum_of_grade_MAX 100
//enum grade {
//	A_plus = 100,
//	A = 90,
//	B_plus = 80,
//	B = 70,
//	C_plus = 60,
//	C = 50,
//	D_plus = 40 ,
//	D = 30,
//	F = 0
//};
int average_of_grade(char* arr[], int size) {
	int sum_of_grade = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == "A+" || arr[i] == "a+" || arr[i] == "A +" || arr[i] == "a +")
			sum_of_grade += 100;
		else if (arr[i] == "A" || arr[i] == "a")
			sum_of_grade += 90;
		else if (arr[i] == "B+" || arr[i] == "b+" || arr[i] == "B +" || arr[i] == "b +")
			sum_of_grade += 80;
		else if(arr[i] == "B" || arr[i] == "b" )s
			sum_of_grade += 70;
		else if (arr[i] == "C+" || arr[i] == "c+" || arr[i] == "C +" || arr[i] == "c +")
			sum_of_grade += 60;
		else if (arr[i] == "C" || arr[i] == "c")
			sum_of_grade += 50;
		else if (arr[i] == "D+" || arr[i] == "d" || arr[i] == "D +" || arr[i] == "d +")
			sum_of_grade += 40;
		else if (arr[i] == "D" || arr[i] == "d")
			sum_of_grade += 30;
		else if (arr[i] == "F" || arr[i] == "f")
			sum_of_grade += 20;
	}
}
int main(int argc, char* argv[]) {
	int subject_number;
	char **subject_grade;
	printf("과목 수를 입력하세요.\n");
	scanf_s("%d", &subject_number);
	subject_grade = (char*)malloc(sizeof(char*) * subject_number);
	
	for (int i = 0; i < subject_number; i++) {
		char sum_of_grade[sum_of_grade_MAX];
		printf("성적을 모두 입력하세요\n");
		scanf("%s", sum_of_grade);
		subject_grade[i] = (char*)malloc(strlen(sum_of_grade) + 1);
		strcpy(subject_grade[i], sum_of_grade);
	}
}