//https://www.acmicpc.net/problem/15654
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 8;
int numbers[MAX];
bool visited[MAX];
int output[MAX];

void perm(int N, int M, int depth)
{
	// depth�� M�� �����ϸ� ���
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << output[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		// ���� ���� ���� ���� �Է�
		if (!visited[i])
		{
			visited[i] = true;
			output[depth] = numbers[i];
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

	// �Է�
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> numbers[i];
	}

	// �Է¹��� ���� ����
	sort(numbers, numbers + N);

	// ���� ���
	perm(N, M, 0);

	return 0;
}