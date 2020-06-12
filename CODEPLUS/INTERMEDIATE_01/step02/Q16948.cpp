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
	
	// strt���� push
	queue<pos> q;
	q.push(strt);
	board[strt.x][strt.y] = 0;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		// end�� �����ϸ� �̵�Ƚ�� ����
		if (x == end.x && y == end.y)
		{
			return board[x][y];
		}

		// 6���� Ž��
		for (int i = 0; i < 6; ++i)
		{
			int nx = x + dr_x[i];
			int ny = y + dr_y[i];
			
			// ���� ���� ����� continue
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			{
				continue;
			}

			// �������� �̵�Ƚ�� > �������� �̵�Ƚ�� + 1 �̸� 
			// �� ���� �� ť�� push
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

	// �Է�
	int N, r1, c1, r2, c2;
	cin >> N >> r1 >> c1 >> r2 >> c2;;
	
	// �ּ� �̵� Ƚ���� ������ ����
	vector<vector<int>> board(N, vector<int>(N, numeric_limits<int>::max()));

	// { r1, c1 } ~ { r2, c2 } �ּ� �̵� Ƚ�� ���
	cout << bfs(board, { r1, c1 }, { r2, c2 });

	return 0;
}