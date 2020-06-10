//https://www.acmicpc.net/problem/9663
#include <iostream>
#include <vector>

using  namespace std;

// 퀸이 이동가능한 8방향
int dr_x[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dr_y[] = {1, 1, 0, -1, -1, -1, 0, 1};
int N, cnt;

// 퀸이 공격 가능한 지점의 값을 +num 하기
void check_8_ways(vector<vector<int>>& check, int x, int y, int num)
{
	for (int i = 0; i < 8; ++i)
	{
		int nx = x + dr_x[i];
		int ny = y + dr_y[i];

		while (!(nx < 0 || nx >= N || ny < 0 || ny >= N))
		{
			check[nx][ny] += num;
			nx += dr_x[i];
			ny += dr_y[i];
		}
	}
}

void go(vector<vector<int>>& check, int row)
{
	// N개의 퀸 자리가 정해지면 카운팅 후 종료
	if (row == N)
	{
		++cnt;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		// 현재까지 정해진 퀸이 공격가능한 지점이 아니면
		if (check[row][i] == 0)
		{
			// 현재지점으로부터 퀸이 공격가능한 모든 지점에 +1
			check_8_ways(check, row, i, 1);
			
			// 다음행의 퀸을 정하기 위해 go함수 재귀호출
			go(check, row + 1);
			
			// 현재지점으로부터 퀸이 공격가능한 모든 지점에 -1
			check_8_ways(check, row, i, -1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> N;
	vector<vector<int>> check(N, vector<int>(N));

	// N개 퀸이 서로 공격할 수 없도록 하는 경우의 수 구하기
	go(check, 0);

	// 출력
	cout << cnt;

	return 0;
}