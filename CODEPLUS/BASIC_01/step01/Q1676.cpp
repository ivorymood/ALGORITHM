//https://www.acmicpc.net/problem/1676
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	// 10 = 2 * 5 �ε�, 
	// 2�� ������� 5�� ����� �� �����Ƿ�
	// �μ� �� 5�� ������ ���� �ȴ�.
	int cnt_5 = 0;
	for (int i = 5; n / i >= 1; i *= 5)
	{
		cnt_5 += n / i;
	}
	cout << cnt_5;

	return 0;
}