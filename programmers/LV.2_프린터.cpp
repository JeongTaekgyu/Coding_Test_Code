#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	queue <pair <int, int>> Que;// �߿䵵 queue �� index�� �ִ� queue �� pair
	priority_queue<int> Pque;	// �켱���� ť�� �˾Ƽ� �������ش�.  default�� less ť (��������)
	int answer = 0;
	int rank = 0;	// �� ��°�� ��µǴ��� �˷��ִ� ��

	for (int i = 0; i < priorities.size(); i++)
	{
		Que.push(make_pair(priorities[i], i));
		Pque.push(priorities[i]);
	}

	while (1)
	{
		if (Que.front().first == Pque.top())	// �߿䵵 ť�� ù��° ���� �켱���� ť�� ù��° ���� ������
		{
			rank++;	// ����� �Ŵϱ� rank ��(�� ��°�� ��µǴ��� �˷���)�� ����
			Pque.pop();

			if (location == Que.front().second)
			{
				answer = rank;
				break;
			}
			else {
				Que.pop();
			}
		}
		else {
			Que.push(Que.front());
			Que.pop();
		}
	}

	return answer;
}

int main()
{
	vector<int> priorities;
	int location;
	int size;
	int temp;

	cin >> size;
	cin >> location;

	for (int i = 0; i < size; i++)
	{
		cin >> temp;
		priorities.push_back(temp);
	}
	
	cout << solution(priorities, location) << endl;
	
	return 0;
}