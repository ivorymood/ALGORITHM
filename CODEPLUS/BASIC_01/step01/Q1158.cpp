//https://www.acmicpc.net/problem/1158
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	// ����� ���
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �Է°� �ޱ�, queue�� [1, N]���� push
	int N, K;
	cin >> N >> K;
	
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	// N - 1ȸ������ ����ϱ�
	cout << '<';
	for (int i = 0; i < N - 1; i++)
	{
		// K���� ���� ��° ���ڴ� ���X, �ٽ� push
		for (int j = 1; j < K; j++)
		{
			q.push(q.front());
			q.pop();
		}

		// K��° ���ڸ� ���O
		cout << q.front() << ", ";
		q.pop();
	}

	// ������ N��° ���� ���
	cout << q.front() << '>';

	return 0;
}