/*
�������� �̺�Ž�� �˰����̸� ���� ���ϴ� ���̱� ������ sorting�� �ʿ����.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int remain_budgets(vector<int>budgets, int mid)
{
	int sum = 0;
	for (int i = 0; i < budgets.size(); i++)
	{
		if (mid - budgets[i] > 0)
			sum += budgets[i];
		else // mid - budgets[i] <= 0
			sum += mid;
	}

	return sum;
}

int solution(vector<int> budgets, int M) {
	int answer = 0;
	int	low = 0;
	int high = 0;

	// max�� ã��
	for (int i = 0; i < budgets.size(); i++)
		high = max(high, budgets[i]);

	while (low <= high)
	{
		int mid = (low + high) / 2;
		int sum = remain_budgets(budgets, mid);

		if (sum == M) // �� ���� ������ ���� �� ����� ������ �ٷ� ���̴�.
		{
			answer = mid;
			return answer;
		}
		else if (sum > M) // �� ���� ������ ���� �� ������ �Ѿ�� �� ������ ������ ��ĭ ������.
		{
			high = mid - 1;
			answer = high;
		}
		else if (sum < M) // �� ���� ������ ���� �� ���� ���� ������ �״�� high(�������� high == mid )�� �������Ѵ�.
		{
			low = mid + 1;
			answer = mid; // sum < M �� ��� �ݺ��� Ż�� ������ high == mid �̴�.
		}
	}

	return answer;
}

int main()
{
	vector<int> budgets;
	int n, m;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		budgets.push_back(temp);
	}

	scanf("%d", &m); // m = budget;

	printf("%d\n", solution(budgets, m));

	return 0;
}