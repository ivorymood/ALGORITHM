//https://www.acmicpc.net/problem/1080
#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<string> &v, int x, int y)
{
	for (int i = x; i < x + 3; ++i)
	{
		for (int j = y; j < y + 3; ++j)
		{
			if (v[i][j] == '0')
			{
				v[i][j] = '1';
			}
			else
			{
				v[i][j] = '0';
			}
		}
	}
}

bool check(vector<string> &from, vector<string> &to)
{
	int N = from.size();
	int M = from[0].size();
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (from[i][j] != to[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, M;
	cin >> N >> M;
	vector<string> from(N), to(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> from[i];
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> to[i];
	}

	/*
		3 * 3 ũ���� ��ȯ�� ������ �������� ����, ���ʿ������� �˻�
		from[i][j]�� to[i][j]�� �ٸ��ٸ�
		from[i][j]�� �������� �ϴ� 3 * 3������ ������ �־�� �Ѵ�.
	*/
	int cnt = 0;
	for (int i = 0; i <= N - 3; ++i)
	{
		for (int j = 0; j <= M - 3; ++j)
		{
			if (from[i][j] != to[i][j])
			{
				reverse(from, i, j);
				++cnt;
			}
		}
	}

	// �� ����� ���� ������ : �ٲ� �� ���� ���
	if (!check(from, to))
	{
		cnt = -1;
	}

	cout << cnt;

	return 0;
}