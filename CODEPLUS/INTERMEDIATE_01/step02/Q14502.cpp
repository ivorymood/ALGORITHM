//https://www.acmicpc.net/problem/14502
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

template<typename T>
using double_v = vector<vector<T>>;

struct pos {
	int x, y;
};

int N, M;
const int NEW_WALL = 3;
enum { LAND, WALL, VIRUS };
int dr_x[] = { 0, 1, 0, -1 };
int dr_y[] = { 1, 0, -1, 0 };
vector<pos> virus;
vector<pos> land;

// bfs�� ���� ���� ���̷��� ���� ���ϱ�
int bfs(double_v<int> test_lab)
{
	// ť�� ���̷��� ������ ��ġ���� push
	queue<pos> q;
	for (int i = 0; i < virus.size(); ++i)
	{
		q.push(virus[i]);
	}

	int virus_cnt = 0;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		// 4���� Ž��
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dr_x[i];
			int ny = y + dr_y[i];

			// ������ ����� continue
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}

			// ���� ��ġ�� �� ĭ�� ��, ���̷��� ī���� �� ť�� push
			if (test_lab[nx][ny] == LAND)
			{
				++virus_cnt;
				test_lab[nx][ny] = VIRUS;
				q.push({ nx, ny });
			}
		}
	}
	return virus_cnt;
}

// dfs�� �� 3�� �����
int dfs(double_v<int>& lab, int cnt, int strt)
{
	/*
		�� 3���� ���� ���������
		�ش� ���ǿ��� ���� ���� ���̷��� ���� ����
	*/
	if (cnt == NEW_WALL)
	{
		return bfs(lab);
	}

	// land ���͸� Ž���ϸ� ����� ��ġ������ �� �����
	int min_virus = 987654321;
	for (int i = strt; i < land.size(); ++i)
	{
		lab[land[i].x][land[i].y] = WALL;

		// ���� �ε������� Ž���ϴ� dfs����Լ� ȣ��. 
		// �ּҰ� ���ϱ�
		min_virus = min(dfs(lab, cnt + 1, i + 1), min_virus);

		lab[land[i].x][land[i].y] = LAND;
	}
	return min_virus;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	cin >> N >> M;
	double_v<int> lab(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> lab[i][j];

			// �� ĭ�� �� : land���Ϳ� ��ġ�� push
			if (lab[i][j] == LAND)
			{
				land.push_back({ i, j });
			}
			// ���̷����� �� : virus���Ϳ� ��ġ�� push
			else if (lab[i][j] == VIRUS)
			{
				virus.push_back({ i, j });
			}
		}
	}

	/*
		�ִ� ���� ���� ���
		�������� : �ʱ� ��ĭ ���� - ���� ���� �� ���� - ���� ���̷��� ����

		--> ���̷����� �ּҷ� �������� �ϴ� 3���� ���� ������ ��.
	*/
	cout << land.size() - NEW_WALL - dfs(lab, 0, 0);

	return 0;
}