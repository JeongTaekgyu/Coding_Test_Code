#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	int cnt;	// n�� �������� ���� �κ��� ����

	// ����ϱ� ��Ģ�� n��° ���� ���� ����� ������ 0�̰�
	// ����� �������� ��Ī�̴�.
	// �׷��Ƿ� �ּ� 1���� ����� �ϹǷ� �ּ� 0 ����
	answer.push_back(-1);	// ����ϱ� ���Ϸ��� -1 �ѰŰ� ���߿� �� 0���� �ٲ��ٰŴ�.

	// answer.resize(cnt); ���ֱ����ؼ� cnt�� ���Ѵ�.
	if (n == 1)
		cnt = 1;
	else {
		cnt = 1;	// �̰� �����ָ� �Ʒ� ��� �ȵȴ�.
		for (int i = 1; i < n; i++)
		{
			cnt = cnt * 2 + 1;
		}
	}

	answer.resize(cnt);	// resize(cnt) ���ִ� ������ answer[i] = 1; �̷������� �ε����� ���ϰ� �����ϱ� ���ؼ�


	if (n == 1)
		return answer;
	else {	// n >= 2
		answer[1] = -1;
		answer[2] = 1;

		if (n == 2)	// n = 2 �̸� �ٷ� ������ n >= 3 �̸� �ؿ� for�� �����Ѵ�.
			answer;
	
		cnt = 3;
		for (int i = 2; i < n; i++)	// i �� �� ������°�� ����� ���ؼ�(���ڷ� Ȱ�� �ȵ�)
		{
			cnt = cnt * 2 + 1;
			answer[cnt/2] = -1;	// �� ����� ������ 0 �̴�.

			for (int j = cnt/2 + 1, k = cnt/2 -1; j < cnt; j++, k--)
			{
				answer[j] = answer[k]*(-1);
			}
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == -1)
			answer[i] = 0;
	}

	return answer;
}
int main()
{
	int n;
	
	cin >> n;

	for (int i = 0; i < solution(n).size(); i++)
	{
		cout << solution(n)[i] << " ";
	}

	return 0;
}