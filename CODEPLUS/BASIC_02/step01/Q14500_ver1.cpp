//https://www.acmicpc.net/problem/14500
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tetromino(vector<vector<int>> &board, int i, int j)
{
	int v_len = board.size();
	int h_len = board[0].size();

	int ttrm_max = 0;

	// Type A - 가로 세로
	if (i < v_len && j + 3 < h_len)
	{
		int t = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
		ttrm_max = max(ttrm_max, t);
	}
	if (i + 3 < v_len && j < h_len)
	{
		int t = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
		ttrm_max = max(ttrm_max, t);
	}

	// Type B
	if (i + 1 < v_len && j + 1 < h_len)
	{
		int t = board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1];
		ttrm_max = max(ttrm_max, t);
	}

	// Type C - 가로 세로
	if (i + 1 < v_len && j + 2 < h_len)
	{
		int t_1 = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j];
		int t_2 = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2];
		int t_3 = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] + board[i][j];
		int t_4 = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] + board[i][j + 2];
		ttrm_max = max({ ttrm_max , t_1, t_2, t_3, t_4 });
	}
	if (i + 2 < v_len && j + 1 < h_len)
	{
		int t_1 = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i][j + 1];
		int t_2 = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1];
		int t_3 = board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1] + board[i][j];
		int t_4 = board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1] + board[i + 2][j];
		ttrm_max = max({ ttrm_max , t_1, t_2, t_3, t_4});
	}

	// Type D - 가로 세로
	if (i + 1 < v_len && j + 2 < h_len)
	{
		int t_1 = board[i][j + 1] + board[i + 1][j + 1] + board[i][j] + board[i + 1][j + 2];
		int t_2 = board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j] + board[i][j + 2];
		ttrm_max = max({ ttrm_max , t_1, t_2 });
	}
	if (i + 2 < v_len && j + 1 < h_len)
	{
		int t_1 = board[i + 1][j] + board[i + 1][j + 1] + board[i][j] + board[i + 2][j + 1];
		int t_2 = board[i + 1][j] + board[i + 1][j + 1] + board[i][j + 1] + board[i + 2][j];
		ttrm_max = max({ ttrm_max , t_1, t_2});
	}

	// Type E - 가로 세로
	if (i + 1 < v_len && j + 2 < h_len)
	{
		int t_1 = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1];
		int t_2 = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] + board[i][j + 1];
		ttrm_max = max({ ttrm_max , t_1, t_2 });
	}
	if (i + 2 < v_len && j + 1 < h_len)
	{
		int t_1 = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1];
		int t_2 = board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1] + board[i + 1][j];
		ttrm_max = max({ ttrm_max , t_1, t_2 });
	}

	return ttrm_max;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N, M;
	cin >> N >> M;

	vector<vector<int>> board(N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int tmp;
			cin >> tmp;
			board[i].push_back(tmp);
		}
	}

	// 테트로미노 최대값 구하기
	int ttrm_max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// 현재위치에서 가능한 테트로미노의 최대값
			ttrm_max = max(ttrm_max, tetromino(board, i, j));
		}
	}

	cout << ttrm_max;

	return 0;
}