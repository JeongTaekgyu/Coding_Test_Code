#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string from, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& temp, vector<string>& answer, int depth)
{
	temp.push_back(from); // 들어 오면 push
	
	if (depth == tickets.size()) // 깊이와 사이즈가 같다면
	{
		answer = temp;	// 지금까지 push한 vector를 answer에 넣어준다.
		return true;
	}
	
	for (int i = 0; i < tickets.size(); i++)
	{
		if (tickets[i][0] == from && visit[i] == false)	// 출발지와 같고 방문하지 않은 곳이라면
		{
			visit[i] = true;	// 방문 표시를 해준다.
			bool success = dfs(tickets[i][1], tickets, visit, temp, answer, depth+1); // 다음 목적지에서 dfs 한다
			
			if (success)
				return true;	// dfs 성공하면 true를 반환
			visit[i] = false;	// 그게 아니면 방문한 곳 취소
		}
	}
	temp.pop_back(); // 없다면 push 한거 빼낸다.
	
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

	for (int i = 0; i < solution(tickets).size(); i++)	// 이렇게하면 solution 함수의 size가 반환된다.
		cout << solution(tickets)[i] << endl;
	
	return 0;
}