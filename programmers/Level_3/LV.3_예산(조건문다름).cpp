/*
전형적인 이분탐색 알고리즘이며 합을 구하는 것이기 때문에 sorting이 필요없다.
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

	// max값 찾기
	for (int i = 0; i < budgets.size(); i++)
		high = max(high, budgets[i]);

	while (low <= high)
	{
		int mid = (low + high) / 2;
		int sum = remain_budgets(budgets, mid);

		if (sum == M) // 각 지방 예산의 합이 총 예산과 같으면 바로 답이다.
		{
			answer = mid;
			return answer;
		}
		else if (sum > M) // 각 지방 예산의 합이 총 예산을 넘어가면 각 지방의 예산을 한칸 내린다.
		{
			high = mid - 1;
			answer = high;
		}
		else if (sum < M) // 각 지방 예산의 합이 총 예산 보다 적으면 그대로 high(마지막엔 high == mid )를 답으로한다.
		{
			low = mid + 1;
			answer = mid; // sum < M 의 경우 반복문 탈출 전에는 high == mid 이다.
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