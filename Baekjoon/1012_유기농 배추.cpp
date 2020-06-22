/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T; // Test case의 수
	int M; // 배추밭 가로의 길이
	int N; // 배추밭 세로의 길이
	int K; // 배추가 심어져 있는 위치의 개수

	cin >> T;
	cin >> M;
	cin >> N;
	cin >> K;



	return 0;
}*/
#include <iostream>
#include <string>
#include <string.h>

#define MAX_SIZE 100

using namespace std;
int m, n, k;

// 상 하 좌 우 (정확한 순서는 좌 상 하 우 순서)
int dy[] = { 0, -1, 1, 0 };
int dx[] = { -1, 0, 0, 1 };

// 배추를 심은 보드
bool cabbage[51][51] = { 0, };

// 배열 방문 여부 체크 
bool visited[51][51] = { 0, };

void dfs(int x, int y) {

	// x,y 좌표 방문 표시 
	visited[x][y] = true;

	// 상 하 좌 우로 이동 하며 탐색 
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 배열의 인덱스를 넘지 않도록 
		if (nx < 0 || ny < 0 || nx >= m || ny >= n)
			continue;

		// 배추가 없으면 탈출 / 방문했다면 탈출 
		if (cabbage[nx][ny] == 0 || visited[nx][ny])
			continue;

		dfs(nx, ny); // 다음칸으로 dfs 이동
	}
}

int main() {
	std::ios::sync_with_stdio(false); cin.tie(0);

	int t; 

	cin >> t;

	while (t > 0) {
		t--;
		cin >> m >> n >> k;
		     //n >> k >> d
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			cabbage[x][y] = true;
		}

		int count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (cabbage[i][j] == 1 && !visited[i][j]) {
					count++;
					dfs(i, j);
				}
			}
		}

		cout << count << endl;

		// 다시 돌거 대비해서 0 으로 초기화 해준다.
		memset(cabbage, 0, sizeof(cabbage));
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}