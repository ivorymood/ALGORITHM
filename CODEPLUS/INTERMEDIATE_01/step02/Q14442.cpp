//https://www.acmicpc.net/problem/14442
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct pos {
	int x, y;
};

struct info {
	pos p;
	int left, dist;
};

int N, M, K;
const int MAX = 1000;
char map[MAX][MAX + 1];
int visit[MAX][MAX];
int dr_x[] = {0, 1, 0, -1};
int dr_y[] = {1, 0, -1, 0};

int bfs()
{
	// visit : ������ �μ� �� ������ ������ �迭 
	// -1������ �ʱ�ȭ
	memset(visit, -1, sizeof(visit));

	// map[0][0]����, �μ��� �ִ� �� K��, �̵�Ƚ�� 1�� ����
	queue<info> q;
	q.push({0, 0, K, 1});
	
	// map[0][0]�� �������� �� �μ� �� �ִ� �� ���� K��
	visit[0][0] = K;
	
	while (!q.empty())
	{
		pos p = q.front().p;
		int left = q.front().left;
		int dist = q.front().dist;
		q.pop();

		// map[N - 1][M - 1]�� �����ϸ� �̵�Ƚ�� ��ȯ
		if (p.x == N - 1 && p.y == M - 1)
		{
			return dist;
		}

		// 4���� Ž��
		for (int i = 0; i < 4; ++i)
		{
			int nx = p.x + dr_x[i];
			int ny = p.y + dr_y[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}

			/* 
				������ġ�� ��ĭ�̰�, 
				������ �� ������ �� ���� �� �ش� ������ �湮�߾��ٸ� 

				visit[nx][ny]�� ���� ���� �� ���� ����
				�̵�Ƚ�� + 1 �ϰ� ���� ������ ť�� push
			*/
			if (map[nx][ny] == '0' && visit[nx][ny] < left)
			{
				visit[nx][ny] = left;
				q.push({nx, ny, left, dist + 1});
			}
			/* 
				�μ� �� �ִ� �� ������ �����ְ�, ������ġ�� ���̰�, 
				������ �� ������ �� ���� �� �ش� ������ �湮�߾��ٸ� 

				visit[nx][ny]�� �μ��� �� �� ���� �� ���� ����
				�̵�Ƚ�� + 1 �ϰ� ���� ������ ť�� push
			*/
			else if (left > 0 && map[nx][ny] == '1' && visit[nx][ny] < left - 1)
			{
				visit[nx][ny] = left - 1;
				q.push({ nx, ny, left - 1, dist + 1 });
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
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> map[i];
	}

	// map[0][0] ~ map[N - 1][M - 1] �ִ� �Ÿ� ��� (�ִ� K�� �� �μ���)
	cout << bfs();

	return 0;
}