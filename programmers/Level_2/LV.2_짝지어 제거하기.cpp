#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<char> c;

	for (int i = 0; i < s.size(); i++)
	{
		if (c.empty() || (c.top() != s[i]))
		{
			c.push(s[i]);
		}
		else if (c.top() == s[i])
		{
			c.pop();
		}
	}

	if (c.empty())
		answer = 1;
	else
		answer = 0;

	return answer;
}
int main()
{
	string s;

	cin >> s;

	cout << solution(s) << endl;

	return 0;
}