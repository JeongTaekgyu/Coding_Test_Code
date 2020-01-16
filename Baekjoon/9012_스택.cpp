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

	return st.empty();	// �������� ���ÿ� ��������� ���� return �Ѵ�.
}

int main()
{
	string str;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (check(str))	// ������ ��������� YES�� ����Ѵ�
		{
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}