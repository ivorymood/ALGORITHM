//https://www.acmicpc.net/problem/13460
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr_x[] = {0, 1, 0, -1};
int dr_y[] = {1, 0, -1, 0};
unsigned int leftright = (1 << 0) | (1 << 2);
unsigned int updown = (1 << 1) | (1 << 3);

struct pos {
	int x, y;
};

pos move_to_end(vector<string>& board, pos M, pos X, int dir)
{
	int back = 1;
	int nx = M.x;
	int	ny = M.y;

	// 다음위치가 벽이 아닐 동안 계속 이동
	while (board[nx][ny] == '.')
	{
		nx += dr_x[dir];
		ny += dr_y[dir];

		// 경로에 다른 구슬이 있을 때 
		// : 다른 구슬 자리를 고려해서 한칸 뒤로 물러나기
		if (nx == X.x && ny == X.y)
		{
			back = 2;
		}
	}

	// 구멍에 빠질 때
	if (board[nx][ny] == 'O')
	{
		return { -1, -1 };
	}

	// 해당 방향으로 이동할 수 있는 최대 지점 반환 
	return { nx - dr_x[dir] * back, ny - dr_y[dir] * back };
}

int go(vector<string> &board, unsigned int now_dir, int cnt, pos R, pos B)
{
	// 10번 초과시 리턴
	if (cnt > 10)
	{
		return cnt;
	}
	
	int min_cnt = 11;

	// 4방향 탐색
	for (int i = 0; i < 4; ++i)
	{
		// 첫 이동이 아니면 : 이전에 이동했던 방향 + 그 반대방향은 제외
		if (cnt != 0 && (now_dir & (1 << i)) == 0)
		{
			continue;
		}

		// i 방향으로 이동한 빨간 구슬, 파란 구슬 위치 구하기
		pos nR = move_to_end(board, R, B, i);
		pos nB = move_to_end(board, B, R, i);
		
		// 둘다 구멍에 빠지지 않았을 경우
		if (nR.x > 0 && nB.x > 0)
		{
			/*
				왼오 <> 위아래 이동가능방향 토글하기

				이번에 왼쪽 or 오른쪽으로 이동했다면, 
				다음번에 또다시 왼쪽 or 오른쪽으로 이동하는 것은 의미가 없다. 
				(같은 방향 이동 or 다시 원위치 이동이기 때문에)

				따라서 다음번 재귀함수 호출시 
				이동 가능한 방향이 겹치지 않도록 토글해준다.
			*/
			int next_dir = ((1 << i) & leftright) ? updown : leftright;

			min_cnt = min(go(board, next_dir, cnt + 1, nR, nB), min_cnt);
		}
		// 빨간 구슬만 구멍에 빠졌을 경우
		else if (nR.x < 0 && nB.x > 0)
		{
			return cnt + 1;
		}
	}

	return min_cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N, M;
	cin >> N >> M;
	vector<string> board(N);
	pos R, B;
	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
		for (int j = 0; j < board[i].size(); ++j)
		{
			// 구슬 위치 저장 후, 입력받은 자리는 '.'으로 대체
			if (board[i][j] == 'R')
			{
				R = { i, j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B')
			{
				B = { i, j };
				board[i][j] = '.';
			}
		}
	}

	// 빨간 구슬만 구멍으로 빼내는 최소 이동 횟수 구하기
	// (10 초과시 -1 출력)
	int cnt = go(board, 0, 0, R, B);
	cout << ((cnt > 10) ? -1 : cnt);

	return 0;
}