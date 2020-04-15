#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<int> que;
	vector<int> push_time(10000);
	int answer = 0;
	int sum = 0;		// �ٸ� ���� �ִ� Ʈ���� ������ ��
	int cnt = 0;		// ��ü �ð�(��)�� ī��Ʈ
	int pass_num = 0;	// �ٸ��� ����� Ʈ��
	int j = 0;			// �ٸ��� �� Ʈ���� ����

	while (true)
	{
		if (j < truck_weights.size() && sum + truck_weights[j] <= weight)// truck_weights ���� ũ�� �������� �����ϰ� �ٸ����԰� �ߵ��� ������ ���� ���� 
		{	// j < truck_weights.size() �� &&�� �������� ���� ��������. �ֳ��ϸ� truck_weights[j]�� ���� �����ؼ� �׷���...
			que.push(truck_weights[j]);
			sum += truck_weights[j];

			push_time.push_back(0);
			j++;	// �ٸ��� �� Ʈ���� ������ ����
		}

		for (int i = pass_num; i < j; i++)	// �ٸ��� �ִ� Ʈ���� �ð��� ���� ��Ų��.
			push_time[i]++;

		if (push_time[pass_num] == bridge_length)	// �ٸ��� ��������
		{
			sum -= que.front();
			que.pop();
			pass_num++;
		}

		cnt++;
		if (pass_num == truck_weights.size())	// �ٸ��� ��� Ʈ���� ��������
		{
			cnt++;	// �������� �� ���� ����� �Ѵ�.
			break;
		}
	}

	answer = cnt;

	return answer;
}
int main()
{
	vector<int> truck_weights;
	int bridge_length;
	int weight;
	int size;
	int temp;

	cin >> bridge_length;
	cin >> weight;
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cin >> temp;
		truck_weights.push_back(temp);
	}

	cout << solution(bridge_length, weight, truck_weights) << endl;

	return 0;
}