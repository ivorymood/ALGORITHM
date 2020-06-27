//https://www.acmicpc.net/problem/2873
#include <iostream>
#include <vector>

using namespace std;

struct pos {
	int x, y;
};

void print_path(vector<vector<int>> &board, const pos &D, int H, int W)
{
	/*
		���� or ���� ���̰� Ȧ���� �� : ¦����� Ȧ������ �����Ͽ� ���

		������������   
		������������ 
		������������  
	*/
	if (H % 2 == 1 || W % 2 == 1)
	{
		for (int h = 0; h < H; ++h)
		{
			for (int w = 0; w < W - 1; ++w)
			{
				cout << (h % 2 == 0 ? 'R' : 'L');
			}

			if (h < H - 1)
			{
				cout << 'D';
			}
		}

		return;
	}

	/*
		����/���� ���̰� ��� ¦���� �� 
		: �־��� �����͸� 3�������� ������, 
		[¦][Ȧ] or [Ȧ][¦]�� ��� �� �ּҰ��� ĭ�� �����ϰ� ��������.
		
		������������   // 1����
		������������ 
		������������   // 2����
		 X����������  
		������������   // 3����
		������������  
	*/

	int part_D = D.x / 2;

	// 1����
	for (int h = 0; h < part_D * 2; ++h)
	{
		for (int w = 0; w < W - 1; ++w)
		{
			cout << (h % 2 == 0 ? 'R' : 'L');
		}
		// ������ ���̸� D�� ������ ����
		if (h < H - 1)
		{
			cout << 'D';
		}
	}

	// 2���� 
	{
		pos S = { part_D * 2, 0 };
		pos E = { part_D * 2 + 1, W - 1 };

		int dr_x[] = { 1, 0, -1, 0 };
		int dr_y[] = { 0, 1, 0, 1 };
		string move = "DRUR";
		int idx = 0;

		while (S.x != E.x || S.y != E.y)
		{
			int n_idx = idx % 4;
			int nx = S.x + dr_x[n_idx];
			int ny = S.y + dr_y[n_idx];

			if (nx == D.x && ny == D.y)
			{
				cout << 'R';
				S.y += 1;
			}
			else
			{
				cout << move[n_idx];
				S.x = nx;
				S.y = ny;
				++idx;
			}
		}

		// ������ ���̸� D�� ������ ����
		if (part_D < H / 2 - 1)
		{
			cout << 'D';
		}
	}

	// 3����
	for (int h = (part_D + 1) * 2; h < H; ++h)
	{
		for (int w = 0; w < W - 1; ++w)
		{
			cout << (h % 2 == 0 ? 'L' : 'R');
		}

		// ������ ���̸� D�� ������ ����
		if (h < H - 1)
		{
			cout << 'D';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int H, W;
	cin >> H >> W;
	vector<vector<int>> board(H, vector<int>(W));
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			cin >> board[i][j];
		}
	}

	pos D = {0, 1};
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			// [¦][Ȧ] or [Ȧ][¦]�� ��� �߿��� �ּҰ� ã��
			if ((i + j) % 2 == 1 && board[D.x][D.y] > board[i][j])
			{
				D = {i, j};
			}
		}
	}

	// [0][0] ~ [H - 1][W - 1]���� ����� ���� �ִ�� �ϴ� ��� ����ϱ�
	print_path(board, D, H, W);

	return 0;
}