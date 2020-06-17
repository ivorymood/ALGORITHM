//https://www.acmicpc.net/problem/10026
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100;
char map[MAX][MAX + 1];
bool visit[MAX][MAX];
int dr_x[] = {0, 1, 0, -1};
int dr_y[] = {1, 0, -1, 0};
int N;
enum {NORMAL, WEAK};

struct pos {
	int x, y;
};

bool possible(char from, char to, int state)
{
	// ���� ���� ���� ���� ���� ��
	if (from == to)
	{
		return true;
	}

	// ���� ������ ���
	if (state == WEAK
		&& ((from == 'G' && to == 'R') || (from == 'R' && to == 'G')))
	{
		return true;
	}
	return false;
}

void bfs(pos now, int state)
{
	queue<pos> q;
	q.push(now);
	visit[now.x][now.y] = true;

	while (!q.empty())
	{
		pos p = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = p.x + dr_x[i];
			int ny = p.y + dr_y[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			{
				continue;
			}
			
			// ���� �湮���� �ʾҰ� 
			// �������� ������� ���� or ����� �� (���� ���ο� ���� �ٸ�)
			if (!visit[nx][ny] 
				&& (possible(map[p.x][p.y], map[nx][ny], state)))
			{
				visit[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int distinguish(int state)
{
	memset(visit, 0, sizeof(visit));

	// ���� �湮���� ���� �����̸� bfs�� ����/����� �� ���� üũ
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!visit[i][j])
			{
				++cnt;
				bfs({ i, j }, state);
			}
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> map[i];
	}
	
	// ���ϻ����� ���, �ƴѰ�� bfsŽ���� 2�� �����Ͽ� ������ ���� ���� ���
	cout << distinguish(NORMAL) << ' ';
	cout << distinguish(WEAK) << '\n';

	return 0;
}