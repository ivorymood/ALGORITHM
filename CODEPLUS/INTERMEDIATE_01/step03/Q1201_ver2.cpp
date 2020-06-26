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

	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
	{
		nums[i] = i = 1;
	}

	/*
		ex) N = 8, M = 4, K = 3 �̸� --> (1)(3 2)(5 4)(8 7 6) ���·� 
		�ִ� ���� K�� �׷� M���� ������ �� �ȿ��� �������ش�.
	*/
	int g_strt = 0;
	for (int i = 1; i <= M; ++i)
	{
		// �� �׷��� �ּ� 1��, �ִ� K�� ��Ҹ� ���� �� �ִ�.
		int g_end = min(g_strt + K, N - M + i);

		// [g_strt, g_end)�� ��ҵ��� ������
		reverse(nums.begin() + g_strt, nums.begin() + g_end);

		// ���� �׷� ������ g_end����
		g_strt = g_end;
	}

	// ���
	for (int i = 0; i < N; ++i)
	{
		cout << nums[i];
	}

	return 0;
}