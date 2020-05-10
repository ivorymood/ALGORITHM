//https://www.acmicpc.net/problem/10973
#include <iostream>

using namespace std;

bool prev_permutation(int A[], int N)
{

	// i : �ڿ������� ���� �Ǵ� ���� �� ���� ������ ������ �ε���
	int i = N - 1;
	while (i > 0 && A[i - 1] < A[i])
	{
		--i;
	}

	// ��ü�� ���������� ���� : ù��° ����
	if (i <= 0)
	{
		return false;
	}

	// j : i - 1 < j , A[i - 1] > A[j] �� ��. 
	// i - 1��° ������ ���� �� ã�� 
	int j = N - 1;
	while (A[i - 1] < A[j])
	{
		--j;
	}

	// i��° ���� j��° ���� �ٲٱ�
	swap(A[i - 1], A[j]);

	// i ��° ������ ���������� ��� ������
	for (int k = i, h = N - 1; k < h; ++k, --h)
	{
		swap(A[k], A[h]);
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 10'000;

	int N;
	cin >> N;
	int A[MAX] = {0,};
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	
	// ���� ������ �����ϸ� ���
	if (prev_permutation(A, N))
	{
		for (int i = 0; i < N; ++i)
		{
			cout << A[i] << ' ';
		}
	}
	// �������� ������ -1 ���
	else
	{
		cout << -1;
	}

	return 0;
}