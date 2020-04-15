#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";

	if (s.length() % 2 == 0)
	{
		answer += s[s.length() / 2 - 1];
		answer += s[s.length() / 2];
		//answer += '\0';
	}
	else {
		answer += s[s.length() / 2];
		//answer += '\0';
	}

	return answer;
}
int main()
{
	string s;

	std::cin >> s;
	std::cout << s << std::endl;

	std::cout << solution(s) << std::endl;

	return 0;
}