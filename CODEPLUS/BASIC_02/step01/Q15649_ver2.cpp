//https://www.acmicpc.net/problem/15649
#include <iostream>

using namespace std;

const int MAX = 8;
int visited[MAX + 1];
char output[MAX * 2 + 1];

void perm(int N, int M, int depth)
{
	// depth�� ��ǥ ���̿� �����ϸ� ���
	if (depth == M)
	{
		cout << output << '\n';
		return;
	}

	// 1~N������ ���� �߿��� M �ڸ��� ���� ���� �����
	for (int i = 1; i <= N; i++)
	{
		// ������ �������� ���� �����߿��� ���� ���� ����
		if (!visited[i])
		{
			visited[i] = true;
			output[depth * 2] = i + '0';
			output[depth * 2 + 1] = ' ';
			perm(N, M, depth + 1);
			visited[i] = false;
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

	perm(N, M, 0);

	return 0;
}