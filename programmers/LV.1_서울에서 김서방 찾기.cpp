#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "�輭���� ";
	string x;

	for (int i = 0; i < seoul.size(); i++)
	{
		if (seoul[i] == "Kim")
			x += to_string(i);	//to_string �� int�� string���� ��ȯ���ִ� �Լ�
	}
	answer += x;
	answer += "�� �ִ�";

	return answer;
}
int main()
{
	vector<string> seoul = {"jane","jeong","lee","Kim","kang"};

	std::cout << solution(seoul) << std::endl;

	return 0;
}