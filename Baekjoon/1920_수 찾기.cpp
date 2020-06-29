// vector���� push�� �ϸ� �ð��� �ʰ��ȴ�..
// cin,cout ���ٴ� scanf,printf �� �ӵ��� �� ������.

// ���� Ž���ϸ� �ð� �ʰ��� ������ ������ -> ����Ž���� �ؾ��Ѵ�.
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

	sort(arr, arr+N); // �������� ����

	for (int i = 0; i < M; i++)
	{
		int temp;
		scanf("%d", &temp);
		solution(N, temp, arr);
	}

	return 0;
}