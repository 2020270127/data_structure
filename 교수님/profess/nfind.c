#include <stdio.h>
#include <string.h>
int nfind(char* string, char* pat) {
	int start = 0;
	int lastS = strlen(string) - 1;
	int lastP = strlen(pat) - 1;
	int endmatch = lastP;

	for (int i = 0; endmatch <= lastS; endmatch++, start++) {
		int j = 0;
		if (string[endmatch] == pat[lastP])//첫 문자와 마지막 문자를 확인하는 방법으로 시간을 줄이려 시도, 
			//하지만 worstcase O는 같음. aaaa, aaba같은 문자열을 생각 
			for (i = start; (j < lastP) && (string[i] == pat[j]); i++, j++);
		if (j == lastP)
			return start;
	}
	return -1;
}