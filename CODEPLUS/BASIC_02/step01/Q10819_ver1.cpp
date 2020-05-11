//https://www.acmicpc.net/problem/10819
#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 8;
int nums[MAX];
int output[MAX];
int visited[MAX];
int max_dif;

void dfs(int N, int M, int depth)
{
	if (M == depth)
	{
		// ���� ���̰� ū ���� ã��
		int t_dif = 0;
		for (int i = 1; i < M; ++i)
		{
			t_dif += abs(output[i] - output[i - 1]);
		}

		if (max_dif < t_dif)
		{
			max_dif = t_dif;
		}

		return;
	}

	// ���� �湮���� ���� ���� ���� -> ���� �ڸ��� ���� dfs(depth + 1) ȣ��
	for (int i = 0; i < N; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			output[depth] = nums[i];
			dfs(N, M, depth + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	// N�� ���� �߿��� N�� �̾Ƽ� ����
	dfs(N, N, 0);

	// �ִ� ���̰� ���
	cout << max_dif;

	return 0;
}