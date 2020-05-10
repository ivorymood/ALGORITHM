//https://www.acmicpc.net/problem/10972
#include <iostream>

using namespace std;

bool next_permutation(int numbers[], int N)
{
	// i : �ڿ������� ���� �Ǵ� ���� �� ���� ������ ������ �ε���
	int i = N - 1;
	while (i > 0 && numbers[i - 1] > numbers[i])
	{
		--i;
	}

	// ��ü�� ���������� ���� : ������ ����
	if (i <= 0)
	{
		return false;
	}

	// j : i - 1 < j , A[i - 1] < A[j] �� ��. 
	// i��° �� �ٷ� ���� ������ ū �� ã�� 
	int j = N - 1;
	while (numbers[i - 1] > numbers[j])
	{
		--j;
	}

	// i��° ���� j��° ���� �ٲٱ�
	swap(numbers[i - 1], numbers[j]);

	// i ��° ������ ���������� ��� ������
	for (int k = i, h = N - 1; k < h; ++k, --h)
	{
		swap(numbers[k], numbers[h]);
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 10000;
	int numbers[MAX];

	// �Է�
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> numbers[i];
	}

	// ���� ������ �����ϸ� ���
	if (next_permutation(numbers, N))
	{
		for (int i = 0; i < N; ++i)
		{
			cout << numbers[i] << ' ';
		}
		cout << '\n';
	}
	// �������� ������ -1 ���
	else
	{
		cout << -1;
	}

	return 0;
}