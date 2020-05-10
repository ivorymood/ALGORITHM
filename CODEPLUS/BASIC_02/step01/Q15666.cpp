//https://www.acmicpc.net/problem/15666
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 8;
int numbers[MAX];
int output[MAX];

void dfs(int N, int M, int depth, int start)
{
	if (depth == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << output[i] << ' ';
		}
		cout << '\n';

		return;
	}

	/*
		�ߺ� ���O, �񳻸����� (���� dfs�� ���� �ε����������� �˻��ϱ�)
	*/
	for (int i = start; i < N; ++i)
	{
		output[depth] = numbers[i];
		dfs(N, M, depth + 1, i);
	}
}


int main()
{
	ios_base::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	int tmp[MAX];
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp[i];
	}

	// �������� ����
	sort(tmp, tmp + N);
	
	// �ߺ� ������ ���� �����
	int idx = 0;
	int num = -1;
	for (int i = 0; i < N; ++i)
	{
		if (num != tmp[i])
		{
			numbers[idx] = tmp[i];
			num = tmp[i];
			++idx;
		}
	}

	// �ߺ� ������ ���� ���� �������� M�� �̱�
	dfs(idx, M, 0, 0);

	return 0;
}