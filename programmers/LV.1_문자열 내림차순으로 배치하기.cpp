#define _CRT_SECURE_NO_WARNINGS
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *solution(char *s)
{
	int i, j;
	char temp;

	printf("%d\n",strlen(s));

	for (i = 0; i < strlen(s); i++)
	{
		for (j = 0; j < strlen(s) - 1; j++)
		{
			if (s[j] < s[j + 1])
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}

	return s;
}
int main()
{
	char *s = (char*)malloc(sizeof(char)*1000);
	char temp;
	int i, j;

	scanf("%s",s);

	printf("%s",solution(s));

	return 0;
}*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string solution(string s)
{
	int i, j;
	char temp;

	for (i = 0; i < s.length(); i++)
	{
		for (j = 0; j < s.length() - 1; j++)
		{
			if (s[j] < s[j + 1])
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}

	return s;
}
int main() {
	
	string s;

	std::cin >> s;
	
	std::cout << solution(s) << std::endl;

	return 0;
}