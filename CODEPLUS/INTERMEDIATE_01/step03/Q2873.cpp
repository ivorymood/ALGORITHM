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
		가로 or 세로 길이가 홀수일 때 : 짝수행과 홀수행을 구분하여 출력

		─────┐   
		┌────┘ 
		└─────  
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
		가로/세로 길이가 모두 짝수일 때 
		: 주어진 데이터를 3구간으로 나누고, 
		[짝][홀] or [홀][짝]인 요소 중 최소값인 칸을 제외하고 지나간다.
		
		─────┐   // 1구간
		┌────┘ 
		└┐┌┐┌┐   // 2구간
		 X└┘└┘│  
		┌────┘   // 3구간
		└─────  
	*/

	int part_D = D.x / 2;

	// 1구간
	for (int h = 0; h < part_D * 2; ++h)
	{
		for (int w = 0; w < W - 1; ++w)
		{
			cout << (h % 2 == 0 ? 'R' : 'L');
		}
		// 마지막 행이면 D를 붙이지 않음
		if (h < H - 1)
		{
			cout << 'D';
		}
	}

	// 2구간 
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

		// 마지막 행이면 D를 붙이지 않음
		if (part_D < H / 2 - 1)
		{
			cout << 'D';
		}
	}

	// 3구간
	for (int h = (part_D + 1) * 2; h < H; ++h)
	{
		for (int w = 0; w < W - 1; ++w)
		{
			cout << (h % 2 == 0 ? 'L' : 'R');
		}

		// 마지막 행이면 D를 붙이지 않음
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
			// [짝][홀] or [홀][짝]인 요소 중에서 최소값 찾기
			if ((i + j) % 2 == 1 && board[D.x][D.y] > board[i][j])
			{
				D = {i, j};
			}
		}
	}

	// [0][0] ~ [H - 1][W - 1]까지 기쁨을 합을 최대로 하는 경로 출력하기
	print_path(board, D, H, W);

	return 0;
}