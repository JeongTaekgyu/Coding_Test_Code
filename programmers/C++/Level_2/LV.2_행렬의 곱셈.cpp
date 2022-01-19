#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	int sum;

	// ex) (3*4) * (4*2) ����� ���ϸ� (3*2) ����� ���;� �ϱ� ������ arr1�� ��� arr2�� ����ŭ �ݺ��Ѵ�.
	for (int i = 0; i < arr1.size(); i++)
	{
		vector<int> row;
		for (int j = 0; j < arr2[0].size(); j++)
		{
			sum = 0;
			for (int k = 0; k < arr2.size(); k++)
			{
				//cout << arr1[i][k] << " " << arr2[k][j] << endl;
				sum +=  arr1[i][k] * arr2[k][j];
			}
			row.push_back(sum);
		}
		answer.push_back(row);
	}

	/*for (int i = 0; i < answer.size(); i++)
	{
		for (int j = 0; j < answer[i].size(); j++)
			cout << answer[i][j] << " ";
		cout << endl;
	}*/

	return answer;
}
int main()
{
	vector<vector<int>> arr1 = { {1, 4}, {3, 2}, {4, 1} };
	vector<vector<int>> arr2 = { {3, 3}, {3, 3} };

	solution(arr1, arr2);
	/*for (int i = 0; i < arr1.size(); i++)
	{
		cout << solution(arr1, arr2)[i] << endl;
	}*/
	
	return 0;
}