//https://www.acmicpc.net/problem/14889
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �� ���� ���� ���� ���ϱ�
int get_dif(vector<vector<int>> &S, int bitset)
{
	int team_s = 0;
	int team_l = 0;
	int len = S.size();

	for (int i = 0; i < len; ++i)
	{
		for (int j = i; j < len; ++j)
		{
			// ��Ʈ�� 1�̸� team_s�� ���� �ջ�
			if (bitset & ((1 << i) | (1 << j)))
			{
				team_s += S[i][j] + S[j][i];
			}
			// ��Ʈ�� 0�̸� team_l�� ���� �ջ�
			if (~bitset & ((1 << i) | (1 << j)))
			{
				team_l += S[i][j] + S[j][i];
			}
		}
	}
	// ������ ���밪 ��ȯ
	return abs(team_s - team_l);
}

// 1�� ������ N / 2�̸� true
bool check(int bitset, int N)
{
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		if (bitset & (1 << i))
		{
			++cnt;
		}
	}
	return cnt == N / 2;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<vector<int>> S(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> S[i][j];
		}
	}

	// ��Ʈ����ũ�� �� ���� ���ϱ�
	int min_dif = 2000;
	for (int i = 1; i < (1 << N); ++i)
	{
		// 1�� ������ N / 2�̸� true
		if (check(i, N))
		{
			// ������ �ּҰ� ���ϱ�
			min_dif = min(min_dif, get_dif(S, i));
		}
	}

	cout << min_dif;

	return 0;
}