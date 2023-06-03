#include <stdio.h>
#include <string.h>

char* (strstr_Plauger)(const char* s1, const char* s2) {
	if (*s2 == '\0')
		return ((char*)s1);
	for (; (s1 = strchr(s1, *s2)) != NULL; ++s1) {//s1에서 패턴 s2를 찾음, 문자 주소 리턴
		const char* sc1, * sc2;

		for (sc1 = s1, sc2 = s2;;)
			if (*++sc2 == '\0')//만약 다음 패턴이 null이면 out, sc2포인터는 다음 문자를 가리킴
				return ((char*)s1);
			else if (*++sc1 != *sc2)//두번째 문자가 두번째 패턴이랑 맞지 않는다면 out, 여기서 sc1포인터가 다음 문자를 가리킴.
				break;
	}
	return (NULL);
} //worst O(패턴의 길이 * 문자열의 길이) 하나하나 비교하니깐
int main() {

}