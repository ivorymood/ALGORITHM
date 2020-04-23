//https://softworking.tistory.com/35
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
	vector<int> input(n);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	/*
		������� ������ ����
		= max(i��°���� "��"�������� �����ϴ� �κм��� ����
			+ i��°���� "��"�������� �����ϴ� �κм��� ����
			- 1)
	*/

	// �տ������� �����ϴ� �κм����� ���� ���ϱ�
	vector<int> icrs_backward(n, 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (input[j] < input[i] && icrs_backward[j] + 1 > icrs_backward[i])
			{
				icrs_backward[i] = icrs_backward[j] + 1;
			}
		}
	}

	// �ڿ������� �����ϴ� �κм����� ���� ���ϱ�
	vector<int> icrs_forward(n, 1);
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (input[i] > input[j] && icrs_forward[j] + 1 > icrs_forward[i])
			{
				icrs_forward[i] = icrs_forward[j] + 1;
			}
		}
	}

	// �ִ밪 ���
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < icrs_backward[i] + icrs_forward[i] - 1)
		{
			max = icrs_backward[i] + icrs_forward[i] - 1;
		}
	}
	cout << max;

	return 0;
}