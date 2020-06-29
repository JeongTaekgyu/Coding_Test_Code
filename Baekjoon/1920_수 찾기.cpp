// vector에서 push로 하면 시간이 초과된다..
// cin,cout 보다는 scanf,printf 가 속도가 더 빠르다.

// 선형 탐색하면 시간 초과가 나오기 떄문에 -> 이진탐색을 해야한다.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void solution(int N, int key, int *arr)
{
	int start_idx = 0;
	int end_idx = N - 1;
	int mid;

	while (end_idx - start_idx >= 0)
	{
		mid = (start_idx + end_idx) / 2;

		if (arr[mid] == key)
		{
			printf("1\n");
			return;
		}
		else if (arr[mid] > key)
			end_idx = mid - 1;
		else
			start_idx = mid + 1;
	}

	printf("0\n");
	return;
}

int main()
{
	int arr[100001];
	int N, M;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		
	}
	scanf("%d", &M);

	sort(arr, arr+N); // 오름차순 정렬

	for (int i = 0; i < M; i++)
	{
		int temp;
		scanf("%d", &temp);
		solution(N, temp, arr);
	}

	return 0;
}