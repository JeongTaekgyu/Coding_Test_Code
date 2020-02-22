#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int edge[1001][1001] = { 0 };
int DFSvisit[1001] = { 0 };
int BFSvisit[1001] = { 0 };
int queue[1001] = { 0 };

void DFS(int v, int N) 
{
	int i;

	DFSvisit[v] = 1;
	printf("%d ", v);
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
	int i, j;
	int front =0, rear =0;

	queue[0] = v;

	BFSvisit[v] = 1;
	printf("%d ",v);

	i = 0;
	while (i < N)
	{
		for (j = 1; j <= N; j++)
		{
			if (edge[v][j] == 1 && BFSvisit[j] == 0)
			{
				BFSvisit[j] = 1;
				rear++;
				queue[rear] = j;
				printf("%d ", j);
			}
		}
		front++;
		v = queue[front];
		i++;
	}

	return;
}

int main() 
{
	int N, M, Start;
	int i, x, y;
	scanf("%d %d %d", &N, &M, &Start);

	for (i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		edge[x][y] = 1;
		edge[y][x] = 1;
	}
	DFS(Start, N);
	printf("\n");
	BFS(Start, N);

	return 0;
}
