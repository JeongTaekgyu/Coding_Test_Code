#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < completion.size(); i++)
	{
		if (completion[i] != participant[i])
		{
			answer = participant[i];
			break;
		}
		if (i == completion.size() - 1) // 다른게 없으면 participant의 마지막사람
			answer = participant[i + 1];
	}

	return answer;
}
int main()
{
	vector<string> participant = { "leo", "zzz", "stanko", "mislav", "taek" };
	vector<string> completion = { "mislav", "taek" ,"leo", "stanko"};

	cout << solution(participant, completion) << endl;

	return 0;
}