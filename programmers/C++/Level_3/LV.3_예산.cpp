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

	// max값 찾기
	for (int i = 0; i < budgets.size(); i++)
		high = max(high, budgets[i]);


	while (1)
	{
		int mid = (low + high) / 2;
		int result = remain_budgets(budgets, mid);

		if (result == M)
			return mid;
		else if (low >= high)
		{
			if (result >= M)
			{
				//printf("%d >= %d\n", result, M);
				//printf("%d, high - 1\n",high-1);
				return high - 1; // 현재 예산이 총 예산을 넘어가면 한칸 내린다
			}
			else // result < M
			{
				//printf("%d < %d\n", result, M);
				//printf("%d, high\n", high);
				return high; // 현재 예산이 총예산보다 적으면 그대로
			}
		}
		else if (result > M)
			high = mid - 1;
		else if (result < M)
			low = mid + 1;
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

	scanf("%d", &m);

	printf("%d\n", solution(budgets, m));

	return 0;
}