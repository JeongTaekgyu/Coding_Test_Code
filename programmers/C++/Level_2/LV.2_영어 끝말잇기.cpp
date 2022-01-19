#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer(2);
	int wrong = 0;
	//int k = 0;
	int cnt = 0;

	answer[0] = 0;
	answer[1] = 0;

	for (int i = 1; i < words.size(); i++)
	{
		// ���� ������ ���ڿ� ������ ù��° ���ڰ� �ٸ��� Ʋ�ȴ�.
		if (words[i - 1][words[i - 1].size() - 1] != words[i][0])
		{
			answer[0] = i % n + 1;	// ���° �������
			answer[1] = i / n + 1;	// Ʋ������� �����ձ� Ƚ��
			break;
		}

		for (int j = 0; j < i; j++)
		{
			if (i != j && words[i].compare(words[j]) == 0)	// �Ȱ����� ������ Ʋ�ȴ�.
			{
				answer[0] = i % n + 1;	// ���° �������
				answer[1] = i / n + 1;	// Ʋ������� �����ձ� Ƚ��
				wrong = 1;
				break;
			}
		}
		if (wrong)
			break;
	}

	// Ʋ������� �����ձ� ���� Ƚ���� ����ϴ� ������ whlie������ (������ i /n + 1)
	// �̰� �ݺ��� �ϳ� ���Ƿ� ��ȿ����
	/*
	k = 0;
	while (k < answer[1])
	{
		k += n;
		cnt++;
	}
	answer[1] = cnt;	// Ʋ������� �����ձ� Ƚ��
	*/

	return answer;
}

int main()
{
	vector<string> words(10);	// cin �Ҷ� ���ϰ� �Ϸ��� �̸� ũ�� ���ߴ�.
	int i = 0;
	int n;
	int size = 0;

	cin >> n;

	// � ����ִ��� �˼� ���µ� �׳� 10�� ���ڤ���
	for (int i = 0; i < 10; i++)
	{
		cin >> words[i];
	}

	for (int i = 0; i < solution(n, words).size(); i++)
	{
		cout << solution(n, words)[i] << endl;
	}

	return 0;
}