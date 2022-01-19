#include <iostream>
#include <string>
#include <vector>

using namespace std;

string dec_to_N(int d, int n) {
	string res = "";
	char code[] = { '0', '1', '2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	
	// d ! = 0 으로 하면 d에 0이 들어올 경우 res에 값이 없기 때문에 
	// while 이후에 res = code[d%n] + res; 값이 있다.
	while (d / n != 0) {
		res = code[d%n] + res;
		d /= n;
	}
	res = code[d%n] + res;

	return res;
}

// n진수 t개 m명중에 p번째
string solution(int n, int t, int m, int p) {
	string answer = "";
	string tmp = "";
	int num;
	int cnt;

	for (int i = 0; i < m*t; i++)
	{
		tmp += dec_to_N(i, n);
	}
	
	cnt = 0;
	for (int i = p - 1; i < tmp.length(); i+= m) 
	{
		answer += tmp[i];
		if (cnt + 1 == t)
			break;
		cnt++;
	}

	return answer;
}
int main()
{
	// n진수 t개 m명중에 p번째
	cout << solution(16, 16, 2, 1) << endl;

	return 0;
}