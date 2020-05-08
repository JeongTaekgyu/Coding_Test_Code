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
			// user[userID(key��)]�� nickName(value��)�� �ִ´�.
		}
	}

	for (int i = 0; i < log.size(); i++) {
		if (log[i][0] == "Enter") {
			answer.push_back(user[log[i][1]] + "���� ���Խ��ϴ�.");
		}
		else if (log[i][0] == "Leave") {
			answer.push_back(user[log[i][1]] + "���� �������ϴ�.");
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
	// getline �ϸ� �� i < n ���� �ϸ� �������� ���� �ļ��� �ϳ� �Է� ���޳�?
	for (int i = 0; i < n; i++)
	{
		getline(cin, record[i]);
	}
	
	//for (int i = 0; i < n; i++)
		//cout << solution(record)[i] << endl;

	// ���� ���� ����ϴ� �Ͱ� vector<string> solution(vector<string> record) �Լ��� ��ȯ���� ���� �ʱ� ������ ���� ó�� ����ϸ� ������ �� �ִ�.
	// �׷��Ƿ� �Ʒ� ó���� �ص� �ȴ�.
	cout << solution(record)[0] << endl;

	return 0;
}