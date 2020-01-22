#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
	long long answer = 0;

	if (sqrt(n) - (long long)sqrt(n) == 0)	// (long long) ������ �ٲ��ָ� �Ҽ��� �Ʒ� ���ڴ� �� �������µ� ���� - ���� == 0 �̸� �����̴�.
	{
		answer = (sqrt(n) + 1)*(sqrt(n) + 1);
	}
	else {
		answer = -1;
	}

	return answer;
}
int main()
{
	long long num;

	cin >> num;

	cout << solution(num) << endl;

	return 0;
}