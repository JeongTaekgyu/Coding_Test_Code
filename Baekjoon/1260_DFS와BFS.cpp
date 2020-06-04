#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> edge(1001, vector<int>(1001, 0));
vector<int> DFSvisit(1001, 0);
vector<int> BFSvisit(1001, 0);
queue<int> que;
// ���������� �־��ϴ� ������ �ֱ���.. ���� ������ �θ� �׶� �׶� ���� �޶� �ٽ� DFS�� �� �� �ִ� ���..

void DFS(int v, int N)
{
	int i;

	DFSvisit[v] = 1;	// �ش� ��带 �湮��
	cout << v << " ";

	for (i = 1; i <= N; i++) {
		if (edge[v][i] == 1 && DFSvisit[i] == 0)
		{	// v - i ���� ������ ���� ���ְ� i�� �湮���� ���� �����̶�� 
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
		cout << v << " "; //bfs�� pop���� �湮��!!

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
	// N : ������ ����
	// M : ������ ����
	// Start : ���� ����� ��ȣ

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