#include <iostream>
#include <string>
#include <stack>
using namespace std;

int check(string str)
{
	stack<char> st;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			st.push(str[i]);
		}
		else {
			if (!st.empty())
				st.pop();
			else
				return false;
		}
	}

	return st.empty();	// 마지막에 스택에 비어있으면 참을 return 한다.
}

int main()
{
	string str;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (check(str))	// 스택이 비어있으면 YES를 출력한다
		{
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}