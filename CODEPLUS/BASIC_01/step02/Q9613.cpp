//https://www.acmicpc.net/problem/9613
#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return GCD(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt;
	cin >> cnt;
	while (cnt--)
	{
		// !! �Է°��� ����, ������ ����ϸ� sum�ڷ����� long long�� �Ǿ�� �Ѵ�
		long long sum = 0;
		
		// �Է�
		int n;
		cin >> n;
		vector<int> input(n);
		for (int i = 0; i < n; i++)
		{
			cin >> input[i];
		}

		// ������ ��� ���� GCD�� ���ϱ�
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				sum += GCD(input[i], input[j]);
			}
		}
		cout << sum << '\n';
	}

	return 0;
}