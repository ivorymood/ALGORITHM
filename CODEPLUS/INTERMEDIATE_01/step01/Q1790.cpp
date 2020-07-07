//https://www.acmicpc.net/problem/1790
#include <iostream>
#include <string>

using namespace std;

// 1���� N���� ���� �̾���� ���� ���ϱ�
long long cal_length(int N)
{
	long long len = 0;
	for (int start = 1, i = 1; start <= N; start *= 10, ++i)
	{
		int end = start * 10 - 1;
		if (end > N)
		{
			end = N;
		}

		len += (long long)(end - start + 1) * i;
	}
	return len;
}

int binary_search(int left, int right, int target)
{
	if (left >= right)
	{
		return right;
	}

	int mid = (left + right) / 2;
	long long len = cal_length(mid);

	/*
		1���� mid���� �̾���� ���� ���� < target �̸�
		[mid + 1, right] �������� �� Ž��
	*/
	if (len < target)
	{
		return binary_search(mid + 1, right, target);
	}
	/*
		1���� mid���� �̾���� ���� ���� >= target �̸�
		[left, mid] �������� �� Ž�� (mid�� ����)
	*/
	else
	{
		return binary_search(left, mid, target);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, K;
	cin >> N >> K;

	// ���� ���̰� K���� ���� ���
	if (cal_length(N) < K)
	{
		cout << -1;
		return 0;
	}

	// 1���� num���� �̾�ٿ��� ���� ���̰� K���� ���ų� ū �ּ��� �� num���ϱ�
	int num = binary_search(1, N, K);

	// 1���� num���� �̾�ٿ��� ���� ���� num_len���ϱ�
	int num_len = cal_length(num);
	
	string s_num = to_string(num);

	// num���� �ڿ��� (num - K)��ŭ �տ� �ִ� ���� ���ϱ�
	cout << s_num[(s_num.size() - 1 - (num_len - K))];

	return 0;
}