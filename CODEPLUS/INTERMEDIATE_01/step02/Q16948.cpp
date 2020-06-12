//https://www.acmicpc.net/problem/16948
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int dr_x[] = {-2, -2, 0, 0, 2, 2};
int dr_y[] = {-1, 1, -2, 2, -1, 1};

struct pos {
	int x, y;
};

int bfs(vector<vector<int>> &board, pos strt, pos end)
{
	int N = board.size();
	
	// strt지점 push
	queue<pos> q;
	q.push(strt);
	board[strt.x][strt.y] = 0;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		// end에 도착하면 이동횟수 리턴
		if (x == end.x && y == end.y)
		{
			return board[x][y];
		}

		// 6방향 탐색
		for (int i = 0; i < 6; ++i)
		{
			int nx = x + dr_x[i];
			int ny = y + dr_y[i];
			
			// 범위 밖을 벗어나면 continue
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			{
				continue;
			}

			// 다음지점 이동횟수 > 현재지점 이동횟수 + 1 이면 
			// 값 갱신 후 큐에 push
			if (board[nx][ny] > board[x][y] + 1)
			{
				board[nx][ny] = board[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N, r1, c1, r2, c2;
	cin >> N >> r1 >> c1 >> r2 >> c2;;
	
	// 최소 이동 횟수를 저장할 벡터
	vector<vector<int>> board(N, vector<int>(N, numeric_limits<int>::max()));

	// { r1, c1 } ~ { r2, c2 } 최소 이동 횟수 출력
	cout << bfs(board, { r1, c1 }, { r2, c2 });

	return 0;
}