#include <iostream>

using namespace std;

int N;
int vx[15 + 1], vy[15 + 1];

int next_row(int y, int x)
{
	// 가지치기(back tracking)
	for (int i = 0; i < y; i++)
	{
		// 직선겹침
		if (y == vy[i])	return 0; // 가로 위치 겹침
		if (x == vx[i])	return 0; // 세로 위치 겹침
		if (abs(x - vx[i]) == abs(y - vy[i])) return 0;	// 대각선 겹침
	}

	// 종료조건
	if (y == N - 1)
	{
		// 말단에서 퀸 배열이 성공적인지 체크
		// 만약 성공적이면 1 리턴
		return 1;
	}

	// 각 행의 말의 위치를 기억
	vy[y] = y;
	vx[y] = x;

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += next_row(y + 1, i);
	}

	return ans;
}
int main()
{

	cin >> N;

	int ans = 0;
	for (int i = 0; i < N; i++)
		ans += next_row(0, i);
	
	cout << ans;

	return 0;
}