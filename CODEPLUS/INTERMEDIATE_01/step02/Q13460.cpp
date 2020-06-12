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

	// ������ġ�� ���� �ƴ� ���� ��� �̵�
	while (board[nx][ny] == '.')
	{
		nx += dr_x[dir];
		ny += dr_y[dir];

		// ��ο� �ٸ� ������ ���� �� 
		// : �ٸ� ���� �ڸ��� ����ؼ� ��ĭ �ڷ� ��������
		if (nx == X.x && ny == X.y)
		{
			back = 2;
		}
	}

	// ���ۿ� ���� ��
	if (board[nx][ny] == 'O')
	{
		return { -1, -1 };
	}

	// �ش� �������� �̵��� �� �ִ� �ִ� ���� ��ȯ 
	return { nx - dr_x[dir] * back, ny - dr_y[dir] * back };
}

int go(vector<string> &board, unsigned int now_dir, int cnt, pos R, pos B)
{
	// 10�� �ʰ��� ����
	if (cnt > 10)
	{
		return cnt;
	}
	
	int min_cnt = 11;

	// 4���� Ž��
	for (int i = 0; i < 4; ++i)
	{
		// ù �̵��� �ƴϸ� : ������ �̵��ߴ� ���� + �� �ݴ������ ����
		if (cnt != 0 && (now_dir & (1 << i)) == 0)
		{
			continue;
		}

		// i �������� �̵��� ���� ����, �Ķ� ���� ��ġ ���ϱ�
		pos nR = move_to_end(board, R, B, i);
		pos nB = move_to_end(board, B, R, i);
		
		// �Ѵ� ���ۿ� ������ �ʾ��� ���
		if (nR.x > 0 && nB.x > 0)
		{
			/*
				�޿� <> ���Ʒ� �̵����ɹ��� ����ϱ�

				�̹��� ���� or ���������� �̵��ߴٸ�, 
				�������� �Ǵٽ� ���� or ���������� �̵��ϴ� ���� �ǹ̰� ����. 
				(���� ���� �̵� or �ٽ� ����ġ �̵��̱� ������)

				���� ������ ����Լ� ȣ��� 
				�̵� ������ ������ ��ġ�� �ʵ��� ������ش�.
			*/
			int next_dir = ((1 << i) & leftright) ? updown : leftright;

			min_cnt = min(go(board, next_dir, cnt + 1, nR, nB), min_cnt);
		}
		// ���� ������ ���ۿ� ������ ���
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

	// �Է�
	int N, M;
	cin >> N >> M;
	vector<string> board(N);
	pos R, B;
	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
		for (int j = 0; j < board[i].size(); ++j)
		{
			// ���� ��ġ ���� ��, �Է¹��� �ڸ��� '.'���� ��ü
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

	// ���� ������ �������� ������ �ּ� �̵� Ƚ�� ���ϱ�
	// (10 �ʰ��� -1 ���)
	int cnt = go(board, 0, 0, R, B);
	cout << ((cnt > 10) ? -1 : cnt);

	return 0;
}