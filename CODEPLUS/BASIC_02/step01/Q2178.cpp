//https://www.acmicpc.net/problem/2178
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100;
int map[MAX][MAX];
bool check[MAX][MAX];
int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };
int N, M;

struct info {
	int x;
	int y;
	int depth;
};

int bfs()
{
	// ť ���� �� �������� ���̰� push
	queue<info> q;
	q.push({ 0, 0, 1 });

	// ť�� �� ������ �ݺ���
	while (!q.empty())
	{
		info tmp = q.front();
		q.pop();
		int x = tmp.x;
		int y = tmp.y;
		int depth = tmp.depth;

		// ť�� map[N][M]�� �����ϸ� ���̰� ��ȯ �� ����
		if (x == N - 1 && y == M - 1)
		{
			return depth;
		}

		// 4���� ���� Ž��
		for (int i = 0; i < 4; ++i)
		{
			int new_x = x + dir_x[i];
			int new_y = y + dir_y[i];

			// ���� ������ map ���� ���� �ְ�
			if (0 <= new_x && new_x < N && 0 <= new_y && new_y < M)
			{
				// ���� ������ ���� �湮���� �ʾҰ� �̵��� �� �ִ� ĭ�� �� 
				if (!check[new_x][new_y] && map[new_x][new_y] > 0)
				{
					// ť�� �ߺ��ؼ� push���� �ʵ��� check
					check[new_x][new_y] = true;
					// ���� ���� ��ġ�� ���� ���̺��� 1 ū �� push
					q.push({ new_x , new_y, depth + 1 });
				}
			}
		}
	}
	return 0;
}

int main()
{
	// �Է�
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	// �ʺ�켱 Ž������ �̷� ��ȸ �� �ּҰ� ���
	printf("%d\n", bfs());

	return 0;
}