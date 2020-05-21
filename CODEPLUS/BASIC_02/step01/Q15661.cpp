//https://www.acmicpc.net/problem/15661
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 20;
int S[MAX][MAX];
int N;
int min_dif = 2000;

// ���� �ջ� ���� ���ϱ�
int get_point(vector<int> &team)
{
	int sum = 0;
	for (int i : team)
	{
		for (int j : team)
		{
			sum += S[i][j];
		}
	}
	return sum;
}

void dfs(vector<int> &team_s, vector<int> &team_l, int index)
{
	if (index == N)
	{
		// ���� �ο��� �ּ� 1�� �̻��̾�� ��
		if (team_s.size() < 1 || team_l.size() < 1)
		{
			return;
		}

		// �ּ� �������� ���ϱ�
		min_dif = min(min_dif, abs(get_point(team_s) - get_point(team_l)));

		return;
	}

	// index��°�� ������ team_s�� ������ ��
	team_s.push_back(index);
	dfs(team_s, team_l, index + 1);
	team_s.pop_back();

	// index��°�� ������ team_l�� ������ ��
	team_l.push_back(index);
	dfs(team_s, team_l, index + 1);
	team_l.pop_back();
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
		for (int j = 0; j < N; ++j)
		{
			cin >> S[i][j];
		}
	}

	// dfs - ��Ʈ��ŷ���� ���� �����ؼ� �������
	vector<int> team_s, team_l;
	dfs(team_s, team_l, 0);

	cout << min_dif;
	
	return 0;
}