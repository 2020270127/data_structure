#include <stdio.h>
#include <string.h>

char* (strstr_Plauger)(const char* s1, const char* s2) {
	if (*s2 == '\0')
		return ((char*)s1);
	for (; (s1 = strchr(s1, *s2)) != NULL; ++s1) {//s1���� ���� s2�� ã��, ���� �ּ� ����
		const char* sc1, * sc2;

		for (sc1 = s1, sc2 = s2;;)
			if (*++sc2 == '\0')//���� ���� ������ null�̸� out, sc2�����ʹ� ���� ���ڸ� ����Ŵ
				return ((char*)s1);
			else if (*++sc1 != *sc2)//�ι�° ���ڰ� �ι�° �����̶� ���� �ʴ´ٸ� out, ���⼭ sc1�����Ͱ� ���� ���ڸ� ����Ŵ.
				break;
	}
	return (NULL);
} //worst O(������ ���� * ���ڿ��� ����) �ϳ��ϳ� ���ϴϱ�
int main() {

}