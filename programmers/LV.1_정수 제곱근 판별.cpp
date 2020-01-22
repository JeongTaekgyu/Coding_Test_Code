#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
	long long answer = 0;

	if (sqrt(n) - (long long)sqrt(n) == 0)	// (long long) 형으로 바꿔주면 소수점 아래 숫자는 다 없어지는데 정수 - 정수 == 0 이면 정수이다.
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