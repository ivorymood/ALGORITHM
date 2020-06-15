//https://www.acmicpc.net/problem/16954
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int N = 8;
char map[N][N + 1];
bool visit[N][N][N];
int dr_x[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dr_y[] = {0, 1, 1, 0, -1, -1, -1, 0, 1};

int bfs()
{
	// map[N - 1][0] ���� 0�ʷ� ����
	queue<tuple<int, int, int>> q;
	q.push({ N - 1, 0, 0 });
	visit[N - 1][0][0] = true;

	while (!q.empty())
	{
		int x, y, time;
		tie(x, y, time) = q.front();
		q.pop();
		
		if (x == 0 && y == N - 1)
		{
			return 1;
		}
		
		// N�� �Ŀ��� map�� ���� ���ԵǹǷ� �ð��� ī��Ʈ �ϴ� ���� �ǹ̰� ����.
		int nt = min(time + 1, N);
		
		// ���ڸ� + �밢�� + �����¿� �� 9���� Ž��
		for (int i = 0; i < 9; ++i)
		{
			int nx = x + dr_x[i];
			int ny = y + dr_y[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			{
				continue;
			}

			/*
				1. t�� ���� map[x][y]�� map[x - t][y]�� ����.
				2. ������ġ�� ���� ������, 1�� �Ŀ� ������ üũ �� �̵�
				3. N�� �Ŀ��� 2�� üũ�� �ǹ̰� ����. map�� ��ֹ��� �����Ƿ�
			*/
			if ((nx - time >= 0 && map[nx - time][ny] == '#')
				|| (nx - time - 1 >= 0 && map[nx - time - 1][ny] == '#'))
			{
				continue;
			}

			/*
				map[x][y]�� �����ϰ� t�� �Ŀ� �湮�߾��ٸ�
				�ٽ� �湮�ϴ� ���� �ǹ̰� ����.
			*/
			if (!visit[nx][ny][nt])
			{
				visit[nx][ny][nt] = true;
				q.push({ nx, ny, nt });
			}
		}
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	for (int i = 0; i < N; ++i)
	{
		cin >> map[i];
	}

	// map[N - 1][0] -> map[0][N - 1] ������ �� �ִ��� ���� ���
	cout << bfs();

	return 0;
}