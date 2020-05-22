//https://www.acmicpc.net/problem/1182
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, S;
	cin >> N >> S;
	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	/*
		i : �κ����� 
		ex) 10101 : 1,3,5 ��° ���� �����ϰ� 2,4��° ���� �������� �ʴ� �κ����� 
	*/
	int cnt = 0;
	for (int i = 1; i < (1 << N); ++i)
	{
		// ���� �κ����տ� ���Ե� ���� �հ� ���ϱ�
		int sum = 0;
		for (int j = 0; j < N; ++j)
		{
			if (i & (1 << j))
			{
				sum += nums[j];
			}
		}

		// �հ谡 S�� ��ġ�ϸ� ����� �� ī��Ʈ
		if (sum == S)
		{
			++cnt;
		}
	}

	cout << cnt;

	return 0;
}