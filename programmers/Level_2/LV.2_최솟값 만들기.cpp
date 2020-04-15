#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end());	// default�� ��������
	sort(B.begin(), B.end(), greater<int>());	// ��������		
	// ���������� ������������ ����� ������ �ؿ��� �׳� �Ȱ��� �ε����� ���ϸ� �ȴ�.

	cout << A.size() << endl;
	cout << B.size() << endl;
	
	for (int i = 0; i < A.size(); i++)
	{
		answer += A[i] * B[i];
	}

	return answer;
}
int main()
{
	vector <int>A;
	vector <int>B;
	int n;
	int tmp;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		B.push_back(tmp);
	}

	cout << solution(A, B) << endl;

	return 0;
}