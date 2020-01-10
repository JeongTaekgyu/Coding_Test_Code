#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
	vector<int> answer;
	long long temp;

	temp = n;

	while (temp != 0)
	{
		answer.push_back(temp % 10);
		temp /= 10;
	}

	return answer;
}
int main()
{
	long long n;

	cin >> n;

	// ������ �ڸ��� ������ִ� �Լ��� ����?
	for (int i = 0; i < 10; i++)
	{
		cout << solution(n)[i];
	}

	return 0;
}