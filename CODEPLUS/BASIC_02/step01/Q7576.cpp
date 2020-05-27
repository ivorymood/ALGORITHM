//https://www.acmicpc.net/problem/7576
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& box, queue<pair<int, int>>& q, int N, int M, int left)
{
	// ������ �丶�䰡 ���ٸ�
	if (left == 0)
	{
		return 0;
	}

	int dir_x[4] = { 0, 1, 0, -1 };
	int dir_y[4] = { 1, 0, -1, 0 };
	int max_d = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		--left;

		// ��� �丶�䰡 ���� ������ �ɸ��� �ϼ� ���ϱ�
		max_d = (max_d < box[x][y]) ? box[x][y] : max_d;

		// 4���� Ž��
		for (int i = 0; i < 4; ++i)
		{
			int new_x = x + dir_x[i];
			int new_y = y + dir_y[i];

			// ���� �� ���� ��ġ�� ��
			if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
			{
				continue;
			}

			// ���� ���� ���� �丶��� ť�� push�ϰ� ���� ���� ��ġ�� �� + 1
			if (box[new_x][new_y] == 0)
			{
				q.push({new_x, new_y});
				box[new_x][new_y] = box[x][y] + 1;
			}
		}
	}

	return (left > 0) ? -1 : max_d - 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int M, N;
	cin >> M >> N;
	vector<vector<int>> box(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> box[i][j];
		}
	}

	queue<pair<int, int>> q;
	int left = M * N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			// ���� �丶��� ť�� push
			if (box[i][j] == 1)
			{
				q.push({ i, j });
			}
			// �丶�䰡 ������ left - 1
			else if (box[i][j] == -1)
			{
				--left;
			}
		}
	}

	/*
		�ʺ�켱 Ž������
		�����°� ������ �丶�䰡 ��� �ͱ������ �ּ� �ϼ� ���ϱ�
	*/
	cout << bfs(box, q, N, M, left);

	return 0;
}