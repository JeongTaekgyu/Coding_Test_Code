#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int block_num = brown + red;
	int t_red;
	int t_brown;
	//red = (���� - 2)*(���� - 2);
	//brown = ���� * ���� - red;

	// ������ ����� 3*3 �� ���� �۱� ������ 3*3 ���� �����Ѵ�.
	// ���� ���� >= ���� �̱� ������ wid = hei ���� �����Ѵ�.
	for (int hei = 3; hei <= block_num/sqrt(block_num); hei++)
	{	// ���� ���� ���� �ش����� ���� ���� == ���� �̱� ������ hei < block_num / block_num�� ������ ���� ����ȴ�. 
		for (int wid = hei; wid <= block_num/3; wid++)
		{	// ���� �ش����� ��츦 �����ϸ� ���δ� ���Ǳ��� �����ϰ� ���ΰ� 3�ΰ�츦 �����غ��� wid <= block_num/3 ���� �����ϴ�
			t_red = (wid - 2)*(hei - 2);
			t_brown = (wid*hei) - t_red;
			if(t_brown == brown && t_red == red)
			{
				answer.push_back(wid);
				answer.push_back(hei);
			}
			
		}
	}

	return answer;
}
int main()
{
	int brown, red;

	cin >> brown;
	cin >> red;

	for (int i = 0; i < 2; i++)
	{
		cout << solution(brown, red)[i] << endl;
	}
	return 0;
}