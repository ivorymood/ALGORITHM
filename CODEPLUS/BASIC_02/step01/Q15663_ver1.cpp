//https://www.acmicpc.net/problem/15663
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 8;

int numbers[MAX];
int output[MAX];
int cnt[MAX];

void dfs(int N, int M, int depth)
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
		��������, �ߺ� ���X
		�ѹ� ���ڸ� �� ������ ���� - 1
		���� ���ڸ� ���� �� �� ������ ���� ����.
	*/
	for (int i = 0; i < N; ++i)
	{
		if (cnt[i] > 0)
		{
			--cnt[i];
			output[depth] = numbers[i];
			dfs(N, M, depth + 1);
			++cnt[i];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
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

	// �� ������ ������ ������ cnt�迭 �����
	// numbers�迭�� �ߺ� ������ ���ڵ� �����ϱ�
	int num = -1;
	int idx = 0;
	for (int i = 0; i < N; ++i)
	{
		if (num != tmp[i])
		{
			num = tmp[i];
			numbers[idx] = tmp[i];
			++cnt[idx];
			++idx;
		}
		else
		{
			++cnt[idx - 1];
		}
	}

	// �ߺ� ������ ���� ���� �߿��� M�� �̱�
	dfs(idx, M, 0);

	return 0;
}