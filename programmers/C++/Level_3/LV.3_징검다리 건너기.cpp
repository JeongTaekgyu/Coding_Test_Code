/*
stones �迭�� ũ��� 200,000 �����̰�
�� ���ҵ��� �� 200,000,000 ������ �ڿ����̱� ������ ������ �̺�Ž�� �ؾ��Ѵ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Cross_The_Bridge(vector<int> stones, int mid, int k)
{
	int cnt = 0;

	for (int i = 0; i < stones.size(); i++)
	{
		if (stones[i] - mid <= 0)
			cnt++;
		else
			cnt = 0;

		if (cnt >= k)
			return false; // �ٸ��� �ǳ� �� ����.
	}

	return true; // �ٸ��� �ǳ� �� �ִ�.
}

int solution(vector<int> stones, int k) {
	int answer = 0;
	int low = 0;
	int high = 0;

	for (int i = 0; i < stones.size(); i++)
		high = max(high, stones[i]);

	while (low <= high)
	{
		int mid = (low + high) / 2;
		bool Cross = Cross_The_Bridge(stones, mid, k);

		if (Cross)
			low = mid + 1;
		else
			high = mid - 1;
	}

	answer = low;
	return answer;
}

int main()
{
	vector<int> stones;
	int k;
	int n;

	scanf("%d",&n);

	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d",&tmp);
		stones.push_back(tmp);
	}
	
	scanf("%d",&k);

	printf("%d\n", solution(stones, k));

	return 0;
}