#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int scoville_value(int min, int second_min)
{
	return min + (2 * second_min);
}
int solution(vector<int> scoville, int K) {
	int answer = 0;
	int temp;
	int input;
	priority_queue<int, vector<int>, greater<int>> pq;	// default�� �������� less<>

	for (int i = 0; i < scoville.size(); i++)
	{
		pq.push(scoville[i]);
	}

	// ��� ������ scoville ������ k �̻��̸� �ȴ�
	while (pq.top() < K && pq.size() > 1)
	{// �׷��Ƿ� ���� ���� ���� k���� �۰ų� pq.size() > 1 �� �� ��� ������Ѵ�.

		temp = pq.top();
		pq.pop();
		input = scoville_value(temp, pq.top());
		//cout << "temp : " << temp << ", pq.top() : " << pq.top() << endl;
		//cout << "input : " << input << endl;
		
		pq.pop(); // ������ 2���� �������� �ϴϱ� pop()�� �� �� ���ش�.
		pq.push(input);	// �������� pq�� �����Ѵ�.

		answer++;
	}

	if (pq.top() < K)
		return -1;

	for (int i = 0; !(pq.empty()); i++)
	{
		cout << pq.top() << " ";
		pq.pop();
	}

	return answer;
}
int main()
{
	priority_queue<int, vector<int>, greater<int>> pq;	// default�� �������� less<>
	vector<int> scoville;
	int size_n;
	int temp;
	int k;

	cin >> size_n;
	cin >> k;

	for (int i = 0; i < size_n; i++)
	{
		cin >> temp;
		scoville.push_back(temp);
	}

	cout << endl << solution(scoville, k) << endl;

	return 0;
}