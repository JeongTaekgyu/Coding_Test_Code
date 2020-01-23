#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer(heights.size(),0);	// ������ ũ�Ⱑ �Ҵ��� �ȵ�ä�� answer[i] = 4; �̷������� �����ϸ� �翬�� ���ξȵǴϱ� �̸� ������ �Ҵ�����
	int left_tower_chk;


	left_tower_chk = 0;
	for (int i = heights.size()-1; i > 0 ; i--)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if (heights[j] > heights[i])// �������� ���鼭 �ڱ⺸�� ū ž ������
			{
				answer[i] = j+1;		// ūž�� ��ġ�� �����ϰ�
				left_tower_chk = 1;		// ���ʿ��� �ڱ⺸�� ūž�� �߰��ߴٴ� ��ȣ�� �߻���Ų��
				break;
			}
		}
		if (left_tower_chk == 0)// ���ʿ� �ڱ⺸�� ū ž�� ������
			answer[i] = 0;
		else
			left_tower_chk = 0;	// ���ʿ� �ڱ⺸�� ū ž�� ������ ���� Ž���� ����  ���ʿ� �ڱ� ���� ū ž�� ���� ���·� ������ش�
	}

	return answer;
}
int main()
{
	vector<int> input;
	int n;
	int temp;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}

	for (int i = 0; i < n; i++)
		cout << solution(input)[i] << " ";
	
	return 0;
}