//https://www.acmicpc.net/problem/15650
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 8;
char output[MAX * 2 + 1];
bool visited[MAX + 1];

void perm(int N, int M, int start, int depth)
{
	// depth�� M�� �����ϸ� ���
	if (depth == M)
	{
		cout << output << '\n';
		return;
	}

	// �μ� start ������ N���� �� �߿��� M���� ���� ����
	for (int i = start; i <= N; i++)
	{
		// ������ �������� ���� ���ڸ� ����
		if (!visited[i])
		{
			visited[i] = true;
			output[depth * 2] = i + '0';
			output[depth * 2 + 1] = ' ';
			
			// ��������: �������ڴ� ���� ���ں��� �� ū ���ڰ� �;���.
			// start �Ķ���� ������ i + 1 �ѱ��
			perm(N, M, i + 1, depth + 1);
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

	perm(N, M, 1, 0);

	return 0;
}