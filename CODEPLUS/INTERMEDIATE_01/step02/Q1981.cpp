//https://www.acmicpc.net/problem/1981
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct pos {
	int x, y;
};

const int MAX = 200;
int N;
int dr_x[] = { 0, 1, 0, -1 };
int dr_y[] = { 1, 0, -1, 0 };
int min_val = MAX;
int max_val = 0;

bool bfs(vector<vector<int>>& board, int mn, int mx)
{
	// [0][0]��ġ�� ��Ұ� ����, ���� ��Ұ� ���� ���̸� false
	if (board[0][0] < mn || board[0][0] > mx)
	{
		return false;
	}

	queue<pos> q;
	q.push({ 0, 0 });
	vector<vector<bool>> visit(N, vector<bool>(N));
	visit[0][0] = true;

	while (!q.empty())
	{
		pos p = q.front();
		q.pop();

		// �־��� ����, ���� ��Ұ����� [N - 1][N - 1]�� ������ �� ������ true
		if (p.x == N - 1 && p.y == N - 1)
		{
			return true;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = p.x + dr_x[i];
			int ny = p.y + dr_y[i];

			// ���� ���̰ų� �湮�� �� ������ continue
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visit[nx][ny])
			{
				continue;
			}

			// ���� ��ġ�� ��Ұ� ����, ���� ��Ұ� ���� ���̸� continue
			if (board[nx][ny] < mn || board[nx][ny] > mx)
			{
				continue;
			}

			visit[nx][ny] = true;
			q.push({ nx, ny });
		}

	}
	// [N - 1][N - 1]�� ������ �� ������ false
	return false;
}

bool check_gap_possible(vector<vector<int>>& board, int gap)
{
	/*
		��Ұ��� ������ [�ּҿ��, �ּҿ�� + gap]�� ��,
		[0][0] ~ [N - 1][N - 1] ������ �� �ִ��� Ȯ��
	*/
	for (int i = min_val; i + gap <= max_val; ++i)
	{
		if (bfs(board, i, i + gap))
		{
			return true;
		}
	}
	return false;
}

// ��(�ִ��� - �ּҿ��)�� �ּҰ��� �̺�Ž������ ã��
int binary_search_gap(vector<vector<int>>& board)
{
	int left = 0;
	int right = max_val - min_val;
	int min_gap = right;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		// mid�� ������ ���� ��, [0][0] ~ [N - 1][N - 1]���� ������ �� �ִ��� Ȯ��
		if (check_gap_possible(board, mid))
		{
			min_gap = min(mid, min_gap);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return min_gap;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];

			// �ּ� ���, �ִ� ��� ���ϱ�
			min_val = min(board[i][j], min_val);
			max_val = max(board[i][j], max_val);
		}
	}

	// ��(�ִ��� - �ּҿ��)�� �ּҰ��� �̺�Ž������ ã��
	cout << binary_search_gap(board);

	return 0;
}