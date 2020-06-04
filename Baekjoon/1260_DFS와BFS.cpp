#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> edge(1001, vector<int>(1001, 0));
vector<int> DFSvisit(1001, 0);
vector<int> BFSvisit(1001, 0);
queue<int> que;
// 전역변수로 둬야하는 이유가 있구나.. 지역 변수로 두면 그때 그때 값이 달라서 다시 DFS로 들어갈 수 있다 등등..

void DFS(int v, int N)
{
	int i;

	DFSvisit[v] = 1;	// 해당 노드를 방문함
	cout << v << " ";

	for (i = 1; i <= N; i++) {
		if (edge[v][i] == 1 && DFSvisit[i] == 0)
		{	// v - i 사이 간선이 열결 되있고 i가 방문하지 않은 정점이라면 
			DFS(i, N);
		}
	}

	return;
}

void BFS(int v, int N)
{
	BFSvisit[v] = 1;
	que.push(v);

	while (!que.empty()) 
	{
		v = que.front();
		que.pop();
		cout << v << " "; //bfs는 pop으로 방문함!!

		for (int i = 1; i <= N; i++) {
			if (edge[v][i] == 1 && BFSvisit[i] == 0)
			{
				que.push(i);
				BFSvisit[i] = 1;
			}
		}
	}

	return;
}
int main()
{
	int N, M, Start;
	int a, b;
	// N : 정점의 개수
	// M : 간선의 개수
	// Start : 시작 노드의 번호

	cin >> N >> M >> Start;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		edge[a][b] = 1;
		edge[b][a] = 1;
	}

	DFS(Start, N);
	cout << endl;
	BFS(Start, N);

	return 0;
}