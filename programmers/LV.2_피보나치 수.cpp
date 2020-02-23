#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ����� �Ǻ���ġ
/*int fibo(int n)
{
	// �� ������ n�� 2�̻��� �Էµȴ� f(n) = f(n-1) + f(n-2)
	// f(0) = 0,  f(1) = 1
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return fibo(n - 1) + fibo(n - 2);
}*/

int solution(int n) 
{
	int answer = 0;
	int a = 0;
	int b = 1;
	
	for (int i = 0; i < n-1; i++)
	{
		answer = (a + b) % 1234567;
		a = b % 1234567;
		b = answer % 1234567;
	}

	return answer;
}
int main()
{
	int n;

	cin >> n;
	cout << solution(n) << endl;

	return 0;
}	