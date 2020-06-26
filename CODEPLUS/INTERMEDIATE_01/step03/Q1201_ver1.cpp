//https://www.acmicpc.net/problem/1201
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, M, K;
	cin >> N >> M >> K;

	/*
		������ ���� ���
		1. �ִ� �κ� ���������� �ִ� �κ� ���� ������ �ϳ��� ���Ҹ� �����Ѵ�.
		2. ��ѱ��� ����
		: N = M * K + 1�̸� ���̰� M + 1�� �������� �Ǵ� ���̰� K + 1�� ���� ������ ���� �� �ִ�.
	*/
	if (N < M + K - 1 || N > M * K)
	{
		cout << -1;
		return 0;
	}



	/*
		�� �׷��� ���� �ε����� ������ strt_idx����
		
		ex) N = 8, M = 4, K = 3 �̸� --> (1)(3 2)(5 4)(8 7 6) ���·� 
			�ִ� ���� K�� �׷� M���� ������ �� �ȿ��� �������ش�.
	*/
	vector<int> strt_idx(M + 1);
	
	// ������ �׷��� �� �ε����� ���� N + 1 ����
	strt_idx[M] = N + 1;

	// �׷��� �ϳ��� �ݵ�� K���� �Ǿ�� �Ѵ�
	N -= K;
	strt_idx[M - 1] = N + 1;

	// ������ �׷��� ũ��� K�� ���� �ʵ��� ������ �й�
	for (int i = M - 2; i >= 0; --i)
	{
		int size = min(K, N / (i + 1));

		N -= size;
		strt_idx[i] = N + 1;

	}



	// strt_idx������ 2��° ��Һ��� �ݺ���
	for (int i = 1; i < strt_idx.size(); ++i)
	{
		// (i��° �׷� ��� - 1)���� (i��° �׷���) ���� �������� ���
		for (int num = strt_idx[i] - 1; num >= strt_idx[i - 1]; --num)
		{
			cout << num << ' ';
		}
	}
		
	return 0;
}