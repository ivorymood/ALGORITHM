//https://www.acmicpc.net/problem/12970
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	
	// A ���� : a, B ���� : b
	for (int a = 1; a < N; ++a)
	{
		/*
			1. a + b = N
			2. a * b >= K
			�϶�, �������� �־��� ������ �����ϴ� ���ڿ��� ���� �� �ִ�.
		*/
		int b = N - a;
		if (a * b < K)
		{
			continue;
		}

		/*
			B�� b����ŭ ���� ��ġ�Ѵ���,
			�� A�� ���ؼ� ��� ��ġ�� ������ �����Ѵ� 
			(���° B�տ� ��ġ�� ������)

			���� A�� ��� B�ڿ� ��ġ�Ѵٸ� (i,j)�� ������ ���� �������� �ʴ´�.
		*/
		vector<int> pos_A(b + 1);
		for (int i = 0; i < a; ++i)
		{
			int after = min(b, K);
			
			++pos_A[b - after];
			K -= after;
		}

		/*
			�� B�տ� ��ġ�ϱ�� ������ A������ŭ ��� ����ϰ� ����
			���ڸ� B�� ����Ѵ�.
		*/
		for (int i = 0; i <= b; ++i)
		{
			for (int j = 0; j < pos_A[i]; ++j)
			{
				cout << 'A';
			}
			if (i < b)
			{
				cout << 'B';
			}
		}
		return 0;
	}

	// ���ڿ� ������ �Ұ����� ���
	cout << -1;

	return 0;
}                          