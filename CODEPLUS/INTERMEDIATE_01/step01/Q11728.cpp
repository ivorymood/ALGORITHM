//https://www.acmicpc.net/problem/11728
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
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
		병합

		두 배열 A, B는 이미 정렬되어 있으므로,
		A, B의 요소를 앞에서부터 비교하여 더 작은수를 먼저 벡터 V에 넣어준다.
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

	// 비교 후 A, B에 남은 요소가 있다면 마저 V에 넣어준다
	while (A_idx < N)
	{
		V[v_i++] = A[A_idx++];
	}
	while (B_idx < M)
	{
		V[v_i++] = B[B_idx++];
	}

	// 출력
	for (int i : V)
	{
		cout << i << ' ';
	}

	return 0;
}