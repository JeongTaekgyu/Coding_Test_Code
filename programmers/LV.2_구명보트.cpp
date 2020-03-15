#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	
	// �ִ� 2����� Ż �� �ִٴ°� �����ϸ� ���� ����.

	sort(people.begin(), people.end());// default�� �������� (less<�ڷ���>())

	if (people.size() == 1)
		return answer = 1;
	// people.size() >= 2 ����
	for (int i = 1, j = 0; i <= people.size() - j; i++)	// i = 1���� �ϱ� ������
	{
		// ���� ��Ʈ ���Ժ��� 2���� ���԰� �� ������ 2���� �� ���ſ� ����� ȥ�ڼ� ����Ʈ�� Ÿ���Ѵ�.
		if (people[j] + people[people.size() - i] > limit)
		{
			answer++;
		}
		else {
			j++;
			answer++;
		}
	}

	return answer;
}
int main()
{
	vector<int> people;
	int n;
	int temp;
	int limit;

	cin >> n;
	cin >> limit;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		people.push_back(temp);
	}

	cout << solution(people, limit) << endl;

	return 0;
}