#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int k;
	int cnt;

	k = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		cnt = 0;
		if (i == prices.size() - 1)
		{
			answer.push_back(0);
			break;
		}
		// ������ ������ answer[�������ε���] = 0 �ְ� break; �ؼ� j = i+1 ���� �����Ѵ�.
		for (int j = i+1; j < prices.size(); j++)
		{
			if (prices[i] <= prices[j])
			{
				cnt++;
			}
			else if(prices[i] > prices[j])
			{
				cnt++;
				answer.push_back(cnt);
				break;
			}
			// �ڱ⺸�� ������ ���� ������ ���� �Ʒ� if�� ����.
			if (j == prices.size() - 1)
			{
				answer.push_back(cnt);
			}
		}
	}

	return answer;
}
int main()
{
	vector<int> prices;
	int n;
	int temp;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		prices.push_back(temp);
	}

	cout << endl;
	for (int i = 0; i < n; i++)
		cout << solution(prices)[i] << endl;

	return 0;
}