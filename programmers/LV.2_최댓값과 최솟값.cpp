#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
	vector<int> a;
	string answer = "";
	int chi;
	int max;
	int min;

	chi = 0;	// ĳ���� �ε����� 0 ���� �ʱ�ȭ
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') 
		{
			a.push_back(stoi(s.substr(chi, i - chi)));
			// cout << chi <<","<< i << ",   "<< stoi(s.substr(chi, i- chi)) << endl;
			// �� ���� ���ڿ�.substr(chi,i)�� chi��° �ε������� i���� �ε�����ŭ ��ȯ�ϴ°ǵ�
			// stoi(s.substr(chi,i))�ϸ� int ������ ��ȯ�ż� �׷���.. ���鳪�ö� ������ ��ȯ�Ѵ�.
			// ���� s.substr(chi, i - chi)�� ���� ������ chi�ε����� ������ �����ε����̰� i�� ������ ������ ������ ���� �ε��� �̱� ������
			chi = i + 1;	// ���鿡�� ��ĭ�� �ڷ� ����ȴ�.(�� ������ ������ ��ĭ�̱� ������)
		}
	}
	a.push_back(stoi(s.substr(chi, s.size())));
	// ���� s.size()�� ������ŭ ��ȯ�ϴ� ������ ���ڰ� ���� ���� ���� �ΰ��� ���µ� ex) 4 52341251 �̷������� �� �� �ִ�.
	// �׷��� �����ϰ� ���������� �ڿ� null ������ ������ ����Ǵ� ������ ���°ǰ� ???

	min = a[0];
	max = a[0];
	for (int i = 1; i < a.size(); i++)	// ������ 0��° �ε����� ���� max, min �̶� 1��° �ε������� ������
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}

	answer += to_string(min);
	answer += " ";
	answer += to_string(max);

	return answer;
}
int main()
{
	string s;
	
	getline(cin, s);

	cout << solution(s) << endl;

	return 0;
}