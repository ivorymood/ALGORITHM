//https://www.acmicpc.net/problem/11728
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(M);
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	for (int i = 0; i < M; ++i)
	{
		cin >> B[i];
	}

	/*
		����

		�� �迭 A, B�� �̹� ���ĵǾ� �����Ƿ�,
		A, B�� ��Ҹ� �տ������� ���Ͽ� �� �������� ���� ���� V�� �־��ش�.
	*/
	vector<int> V(N + M);
	int A_idx = 0, B_idx = 0, v_i = 0;

	while (A_idx < N && B_idx < M)
	{
		if (A[A_idx] <= B[B_idx])
		{
			V[v_i++] = A[A_idx++];
		}
		else
		{
			V[v_i++] = B[B_idx++];
		}
	}

	// �� �� A, B�� ���� ��Ұ� �ִٸ� ���� V�� �־��ش�
	while (A_idx < N)
	{
		V[v_i++] = A[A_idx++];
	}
	while (B_idx < M)
	{
		V[v_i++] = B[B_idx++];
	}

	// ���
	for (int i : V)
	{
		cout << i << ' ';
	}

	return 0;
}