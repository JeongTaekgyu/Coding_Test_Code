#include <iostream>
using namespace std;

int solution(int n)
{
	int ans = 0; // ó������ ������ ��ĭ �����ϰ� �����ؾ� �Ѵ�.
	
	while (n > 0)
	{
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else if(n % 2 == 1)
		{
			n -= 1;
			ans++;
		}
	}

	return ans;
}
int main()
{
	int N;

	cin >> N;
	
	cout << solution(N) << endl;

	return 0;
}