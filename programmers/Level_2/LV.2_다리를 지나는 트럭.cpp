#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<int> que;
	vector<int> push_time(10000);
	int answer = 0;
	int sum = 0;		// 다리 위에 있는 트럭의 무게의 합
	int cnt = 0;		// 전체 시간(초)을 카운트
	int pass_num = 0;	// 다리를 통과한 트럭
	int j = 0;			// 다리에 들어간 트럭의 순서

	while (true)
	{
		if (j < truck_weights.size() && sum + truck_weights[j] <= weight)// truck_weights 벡터 크기 전까지만 참조하고 다리무게가 견딜수 있으면 차량 삽입 
		{	// j < truck_weights.size() 가 &&의 우측으로 가면 에러난다. 왜냐하면 truck_weights[j]를 먼저 참조해서 그렇다...
			que.push(truck_weights[j]);
			sum += truck_weights[j];

			push_time.push_back(0);
			j++;	// 다리에 들어간 트럭의 순서를 증가
		}

		for (int i = pass_num; i < j; i++)	// 다리에 있는 트럭의 시간만 증가 시킨다.
			push_time[i]++;

		if (push_time[pass_num] == bridge_length)	// 다리를 지나가면
		{
			sum -= que.front();
			que.pop();
			pass_num++;
		}

		cnt++;
		if (pass_num == truck_weights.size())	// 다리를 모든 트럭이 지나가면
		{
			cnt++;	// 마지막에 한 번더 해줘야 한다.
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