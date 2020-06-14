//https://www.acmicpc.net/problem/16946
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct pos {
	int x, y;
};

int N, M;
int dr_x[] = { 0, 1, 0, -1 };
int dr_y[] = { 1, 0, -1, 0 };
const int MAX = 1000;
char map[MAX][MAX + 1];
int group[MAX][MAX];

int bfs(pos strt, int idx)
{
	// ť�� �������� push �� group�� idx�� ����
	queue<pos> q;
	q.push(strt);
	group[strt.x][strt.y] = idx;

	int cnt = 1;
	while (!q.empty())
	{
		pos p = q.front();
		q.pop();

		// 4���� Ž��
		for (int i = 0; i < 4; ++i)
		{
			int nx = p.x + dr_x[i];
			int ny = p.y + dr_y[i];

			// ������ �Ѿ�� continue
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}

			// ���� ������ ��ĭ�̰� ���� group�� �ε����� �ű��� �ʾҴٸ�
			if (map[nx][ny] == '0' && group[nx][ny] == 0)
			{
				++cnt;
				group[nx][ny] = idx;
				q.push({ nx, ny });
			}
		}
	}
	// �ش� ��ĭ�׷��� ����ũ�� ��ȯ
	return cnt;
}

void plus_adj_group(vector<int>& cnts, pos p)
{
	set<int> s;
	// 4���� Ž��
	for (int k = 0; k < 4; ++k)
	{
		int nx = p.x + dr_x[k];
		int ny = p.y + dr_y[k];

		// ������ �Ѿ�� continue
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
		{
			continue;
		}

		// ���� ������ ��ĭ�̸� set�� �׷� �ε��� push (�ߺ� ����)
		if (map[nx][ny] == '0')
		{
			s.insert(group[nx][ny]);
		}
	}

	// ������ ��ĭ�׷� �ε����� ����ũ�� ���ϱ�
	int num = 1;
	for (int idx : s)
	{
		num += cnts[idx];
	}
	num %= 10;

	map[p.x][p.y] = num + '0';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> map[i];
	}

	/*
		Flood Fill
		cnts �迭�� �� ��ĭ �׷��� ����� ���� ũ�⸦ ������� ����
	*/
	vector<int> cnts(1);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			// map[i][j]�� ��ĭ�̰� group�� �ε����� �Ű����� �ʾ�����
			if (map[i][j] == '0' && group[i][j] == 0)
			{
				// bfs�� group�迭�� �ε����� ���� ��, cnts�迭�� ����ũ�� ����
				cnts.push_back(bfs({ i, j }, cnts.size()));
			}
		}
	}

	// map[i][j]�� ���̸�, ������ ��ĭ�׷��� ����ũ�⸦ ���Ѵ�
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (map[i][j] == '1')
			{
				plus_adj_group(cnts, { i, j });
			}
		}
	}

	// ���
	for (int i = 0; i < N; ++i)
	{
		cout << map[i] << '\n';
	}

	return 0;
}