#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<vector<string>> log(record.size(), vector<string>(3));
	map<string, string> user;	// userID : nickName = key : value

	for (int i = 0; i < record.size(); i++) {
		istringstream iss(record[i]);
		iss >> log[i][0];
		iss >> log[i][1];
		iss >> log[i][2];
		if (log[i][0] == "Enter" || log[i][0] == "Change") 
		{
			user[log[i][1]] = log[i][2];
			// user[userID(key값)]에 nickName(value값)를 넣는다.
		}
	}

	for (int i = 0; i < log.size(); i++) {
		if (log[i][0] == "Enter") {
			answer.push_back(user[log[i][1]] + "님이 들어왔습니다.");
		}
		else if (log[i][0] == "Leave") {
			answer.push_back(user[log[i][1]] + "님이 나갔습니다.");
		}
	}

	cout << "-----------------" << endl;
	map<string, string>::iterator iter;

	for (iter = user.begin(); iter != user.end(); iter++)
	{
		cout << iter->first << "," << iter->second<< endl;
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}

	return answer;
}

int main()
{
	vector<string> record(10);
	string temp;
	int n;
	
	cin >> n;
	record.resize(n);
	cout << record.size() << endl;

	cin >> ws;
	// getline 하면 왜 i < n 으로 하면 마지막에 엔터 쳐서서 하나 입력 못받나?
	for (int i = 0; i < n; i++)
	{
		getline(cin, record[i]);
	}
	
	//for (int i = 0; i < n; i++)
		//cout << solution(record)[i] << endl;

	// 단지 내가 출력하는 것과 vector<string> solution(vector<string> record) 함수의 반환형이 맞지 않기 때문에 위에 처럼 출력하면 에러날 수 있다.
	// 그러므로 아래 처럼만 해도 된다.
	cout << solution(record)[0] << endl;

	return 0;
}