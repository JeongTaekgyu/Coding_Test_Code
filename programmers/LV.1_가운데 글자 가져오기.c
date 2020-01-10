#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* solution(char *s)
{
	char *answer = (char*)malloc(sizeof(char)*3);

	if (strlen(s) % 2 == 0)
	{
		answer[0] = s[strlen(s) / 2 - 1];
		answer[1] = s[strlen(s) / 2 ];
		answer[2] = '\0';
	}
	else {
		answer[0] = s[strlen(s)/2];
		answer[1] = '\0';
	}

	return answer;
}
int main()
{
	char s[101];

	scanf("%s", s);

	printf("%s",solution(s));

	return 0;
}
