//https://www.acmicpc.net/problem/1463
#include <iostream>

using namespace std;

const int MAX = 1000000;
int M[MAX + 1];

// ��ȭ�� : D[n] = min(D[n - 1] + 1, D[n / 2] + 1, D[n / 3] + 1)
int make_one(int n)
{
	// ��������
	if (n == 1)
	{
		return 0;
	}

	if (M[n] > 0)
	{
		return M[n];
	}

	// 10->9->3->1 �� ���� �ݷʰ� ���� �� �����Ƿ�,
	// 1 ~ N ������ ��� ����� ���� �̸� ����
	M[n] = make_one(n - 1) + 1;
	
	// ���� ����� �� > ���� ���� ���� ��, �����ϱ�
	if (n % 2 == 0)
	{
		int temp = make_one(n / 2) + 1;
		if (M[n] > temp) M[n] = temp;
	}

	if (n % 3 == 0)
	{
		int temp = make_one(n / 3) + 1;
		if (M[n] > temp) M[n] = temp;
	}

	return M[n];
}

int main()
{
	int n;
	cin >> n;

	make_one(n);

	cout << M[n];

	return 0;
}