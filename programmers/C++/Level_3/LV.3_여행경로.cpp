#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string from, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& temp, vector<string>& answer, int depth)
{
	temp.push_back(from); // ��� ���� push
	
	if (depth == tickets.size()) // ���̿� ����� ���ٸ�
	{
		answer = temp;	// ���ݱ��� push�� vector�� answer�� �־��ش�.
		return true;
	}
	
	for (int i = 0; i < tickets.size(); i++)
	{
		if (tickets[i][0] == from && visit[i] == false)	// ������� ���� �湮���� ���� ���̶��
		{
			visit[i] = true;	// �湮 ǥ�ø� ���ش�.
			bool success = dfs(tickets[i][1], tickets, visit, temp, answer, depth+1); // ���� ���������� dfs �Ѵ�
			
			if (success)
				return true;	// dfs �����ϸ� true�� ��ȯ
			visit[i] = false;	// �װ� �ƴϸ� �湮�� �� ���
		}
	}
	temp.pop_back(); // ���ٸ� push �Ѱ� ������.
	
	return false; 
} 

vector<string> solution(vector<vector<string>> tickets) 
{ 
	vector<string> answer, temp;
	vector<bool> visit(tickets.size(), false); 
	
	sort(tickets.begin(), tickets.end()); 
	
	dfs("ICN", tickets, visit, temp, answer, 0); 
	
	return answer; 
}

int main()
{
	//vector<vector<string>> tickets = { {"ICN", "JFK" }, { "HND", "IAD" }, { "JFK", "HND" } };
	vector<vector<string>> tickets = { {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"} };

	for (int i = 0; i < solution(tickets).size(); i++)	// �̷����ϸ� solution �Լ��� size�� ��ȯ�ȴ�.
		cout << solution(tickets)[i] << endl;
	
	return 0;
}