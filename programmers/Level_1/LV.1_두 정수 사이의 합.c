#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long long solution(int a, int b) {
	long long answer = 0;
	int i;

	if (a < b) 
	{
		for (i = a; i <= b; i++)
			answer += i;
	}
	else if (a > b)
	{
		for (i = b; i <= a; i++)
			answer += i;
	}
	else
		answer = a;

	return answer;
}
int main()
{
	long long a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n", solution(a, b));
	return 0;
}