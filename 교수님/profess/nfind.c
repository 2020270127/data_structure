#include <stdio.h>
#include <string.h>
int nfind(char* string, char* pat) {
	int start = 0;
	int lastS = strlen(string) - 1;
	int lastP = strlen(pat) - 1;
	int endmatch = lastP;

	for (int i = 0; endmatch <= lastS; endmatch++, start++) {
		int j = 0;
		if (string[endmatch] == pat[lastP])//ù ���ڿ� ������ ���ڸ� Ȯ���ϴ� ������� �ð��� ���̷� �õ�, 
			//������ worstcase O�� ����. aaaa, aaba���� ���ڿ��� ���� 
			for (i = start; (j < lastP) && (string[i] == pat[j]); i++, j++);
		if (j == lastP)
			return start;
	}
	return -1;
}