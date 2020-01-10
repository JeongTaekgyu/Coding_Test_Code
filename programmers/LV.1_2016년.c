#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b) {
	// 리턴할 값은 메모리를 동적 할당해주세요.
	char* answer = (char*)malloc(sizeof(char*)*4);

	char days[7][4] = { "THU","FRI","SAT","SUN","MON","TUE","WED" };
	char month[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int i, j;
	int sum_day = 0;

	for (i = 0; i < a-1; i++)
	{
		sum_day += month[i]; 
	}
	sum_day += b;

	for (i = 0; i < 4; i++)
	{
		answer[i] = days[sum_day % 7][i];
	}
	
	return answer;
}

int main()
{
	int a, b;

	scanf("%d %d",&a,&b);

	printf("%s\n", solution(a,b));

	return 0;
}