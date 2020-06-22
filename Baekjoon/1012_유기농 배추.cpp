/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T; // Test case�� ��
	int M; // ���߹� ������ ����
	int N; // ���߹� ������ ����
	int K; // ���߰� �ɾ��� �ִ� ��ġ�� ����

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

// �� �� �� �� (��Ȯ�� ������ �� �� �� �� ����)
int dy[] = { 0, -1, 1, 0 };
int dx[] = { -1, 0, 0, 1 };

// ���߸� ���� ����
bool cabbage[51][51] = { 0, };

// �迭 �湮 ���� üũ 
bool visited[51][51] = { 0, };

void dfs(int x, int y) {

	// x,y ��ǥ �湮 ǥ�� 
	visited[x][y] = true;

	// �� �� �� ��� �̵� �ϸ� Ž�� 
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// �迭�� �ε����� ���� �ʵ��� 
		if (nx < 0 || ny < 0 || nx >= m || ny >= n)
			continue;

		// ���߰� ������ Ż�� / �湮�ߴٸ� Ż�� 
		if (cabbage[nx][ny] == 0 || visited[nx][ny])
			continue;

		dfs(nx, ny); // ����ĭ���� dfs �̵�
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

		// �ٽ� ���� ����ؼ� 0 ���� �ʱ�ȭ ���ش�.
		memset(cabbage, 0, sizeof(cabbage));
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}