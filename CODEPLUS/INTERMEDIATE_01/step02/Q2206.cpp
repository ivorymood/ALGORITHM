//https://www.acmicpc.net/problem/2206
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct pos {
	int x, y;
};

struct info {
	pos p;
	int left; // left ��ŭ ���� �μ� �� �ִ�
	int dist; // �̵�Ƚ��
};

int N, M;
int dr_x[] = {0, 1, 0, -1};
int dr_y[] = {1, 0, -1, 0};
const int MAX = 1000;
int visit[MAX][MAX];

int bfs(vector<string>& map)
{
	// visit : ������ �μ� �� ������ ������ �迭
	// -1������ �ʱ�ȭ
	memset(visit, -1, sizeof(visit));

	// map[0][0]����, �μ��� �ִ� �� 1��, �̵�Ƚ�� 1�� ����
	queue<info> q;
	q.push({0, 0, 1, 1});
	
	// map[0][0]�� �������� �� �μ� �� �ִ� �� ���� 1��
	visit[0][0] = 1;

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

			// ������ ����� continue
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}

			/*
				������ġ�� ��ĭ�̰�, 
				������ �� ������ �� ���� �� �ش� ������ �湮�߾��ٸ�
			*/
			if (map[nx][ny] == '0' && visit[nx][ny] < left)
			{
				// visit[nx][ny]�� ���� ���� �� ���� ����
				visit[nx][ny] = left;
				
				// �̵�Ƚ�� + 1 �ϰ� ���� ������ ť�� push
				q.push({ nx, ny, left, dist + 1 });
			}
			/*
				�μ� �� �ִ� �� ������ �����ְ�, ������ġ�� ���̰�, 
				������ �� ������ �� ���� �� �ش� ������ �湮�߾��ٸ�
			*/
			else if (left > 0 && map[nx][ny] == '1' && visit[nx][ny] < left - 1)
			{
				// visit[nx][ny]�� �μ��� �� �� ���� �� ���� ����
				visit[nx][ny] = left - 1;

				// �̵�Ƚ�� + 1 �ϰ� ���� ������ ť�� push
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
	cin >> N >> M;
	vector<string> map(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> map[i];
	}

	// map[0][0] ~ map[N - 1][M - 1] �ִ� �Ÿ� ���
	cout << bfs(map);

	return 0;
}