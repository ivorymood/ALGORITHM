//https://www.acmicpc.net/problem/16197
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr_x[4] = { 0, 1, 0, -1 }; 
int dr_y[4] = { 1, 0, -1, 0 };
int N, M, min_cnt = 11;
vector<vector<char>> map;

// ���� �ۿ� �ִ��� üũ
bool inline is_out(int x, int y)
{
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void go(pair<int, int> coin1, pair<int, int> coin2, int cnt)
{
	// �̵�Ƚ���� �ּҰ����� Ŀ���� ����
	if (cnt >= min_cnt)
	{
		return;
	}

	// 4���� Ž��
	for (int i = 0; i < 4; ++i)
	{
		// �� ������ ���� ��ġ
		int nc1_x = coin1.first + dr_x[i];
		int nc1_y = coin1.second + dr_y[i];
		int nc2_x = coin2.first + dr_x[i];
		int nc2_y = coin2.second + dr_y[i];

		// ���� ������ ���� ���� ���� ����
		int left = 2;
		if (is_out(nc1_x, nc1_y))
		{
			--left;
		}
		if (is_out(nc2_x, nc2_y))
		{
			--left;
		}

		// ������ 1�� ���Ҵٸ� �ּҰ� ���� �� ����
		if (left == 1)
		{
			min_cnt = min(cnt + 1, min_cnt);
			return;
		}
		// ������ 2�� ���Ҵٸ�
		else if (left == 2)
		{
			// ���� ĭ�� ���϶� -> ���� ��ġ�� ��ü
			int move = 2;
			if (map[nc1_x][nc1_y] == '#')
			{
				nc1_x = coin1.first;
				nc1_y = coin1.second;
				--move;
			}
			if (map[nc2_x][nc2_y] == '#')
			{
				nc2_x = coin2.first;
				nc2_y = coin2.second;
				--move;
			}
			
			// �� �����̶� ������ �� ������ go ����Լ� ȣ��
			if (move > 0)
			{
				go({ nc1_x, nc1_y }, { nc2_x, nc2_y }, cnt + 1);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	cin >> N >> M;
	map = vector<vector<char>>(N, vector<char>(M));
	vector<pair<int, int>> coins;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];

			// �����̸� ���Ϳ� push
			if (map[i][j] == 'o')
			{
				coins.push_back({i, j});
			}
		}
	}

	// �� ������ �ʱⰪ���� go�Լ� ȣ��
	go(coins[0], coins[1], 0);
	
	// �̵�Ƚ���� 10�� �ʰ��ϸ� -1 ���
	if (min_cnt > 10)
	{
		min_cnt = -1;
	}

	cout << min_cnt << '\n';

	return 0;
}