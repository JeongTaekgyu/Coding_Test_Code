// ex) -> ababcdcdababcdcd �� 2ababcdcd �� �ٲٴ°� �ƴ϶� �� ������ 9�� ���ϴ� ���̴�.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s) {
	int answer = s.length();

	for (int i = 1; i <= s.length() / 2; i++)
	{	// ���ڿ��� ���ݱ����� �˻��ϸ� �ȴ�.
		int pos = 0;
		int len = s.length();

		while(1)
		{
			string unit = s.substr(pos, i); // pos �ε������� i ���̸�ŭ �����´�.
			pos += i;

			if (pos >= s.length())
				break;

			int cnt = 0;
			while(1)
			{
				if (unit.compare(s.substr(pos, i)) == 0) { // ������ ���ڿ� �̶��
					cnt++;
					pos += i;
				}
				else {break;}
			}
			
			if (cnt > 0) { // ����Ȱ� �ִٸ�
				len -= i * cnt; // (���ڿ� ���� x �ݺ��� Ƚ��)��ŭ ���ش�.
				
				if(cnt < 9)len += 1;
				else if (cnt < 99) len += 2;
				else if (cnt < 999) len += 3;
				else len += 4; // �Ѱ��� ���ڷθ� �̷���� ���̰� 1000�� ���ڿ��� ���;
			}
		}
		answer = min(answer, len); // ���� ������ ������ �Ѵ�.
	}

	return answer;
}

int main()
{
	string s;

	cin >> s;

	printf("%d\n", solution(s));

	return 0;
}