//https://www.acmicpc.net/problem/13398
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int n;
	cin >> n;
	vector<int> input(n + 2);	// �� ���� 1ĭ�� ������ �д�. 
	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}

	/*
		DL[i] : ���ʿ������� i������ �ִ� ������
		DR[i] : �����ʿ������� i������ �ִ� ������
	*/
	vector<int> DL(n + 2);
	vector<int> DR(n + 2);
	for (int i = 1; i <= n; i++)
	{
		DL[i] = input[i];
		DR[n - i + 1] = input[n - i + 1];

		if (DL[i - 1] >= 0)
		{
			DL[i] += DL[i - 1];
		}
		if (DR[n - i + 2] >= 0)
		{
			DR[n - i + 1] += DR[n - i + 2];
		}
	}

	// ���� �������� �ʾ��� �� �ִ밪 ���ϱ�
	// ���� �ݵ�� �Ѱ� �̻� �����ؾ� �ϱ� ������ �ʱⰪ = DL[1]
	int max = DL[1];
	for (int i = 2; i <= n; i++)
	{
		if (max < DL[i])
		{
			max = DL[i];
		}
	}

	/*
		���� �������� �� �ִ밪 ���ϱ�

		i��° ���� �������� ��, i��° ���� ���ԵǴ� �ִ� ������
		--> DL[i - 1] + DR[i + 1]
	*/
	for (int i = 2; i <= n; i++)
	{
		if (max < DL[i - 1] + DR[i + 1])
		{
			max = DL[i - 1] + DR[i + 1];
		}
	}
	cout << max;

	return 0;
}