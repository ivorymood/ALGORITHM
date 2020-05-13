//https://www.acmicpc.net/problem/9095
#include <iostream>

using namespace std;

int recurr(int sum, int goal)
{
	// ���� ��ǥ ���ں��� Ŭ�� : �Ұ����� ������
	if (sum > goal)
	{
		return 0;
	}
	// �� = ��ǥ �����϶� : ������ ������
	else if (sum == goal)
	{
		return 1;
	}

	// (1, 2, 3)�� ���ؼ� ��ǥ ���ڰ� �Ǵ� ������ ���ϱ�
	return recurr(sum + 1, goal) + recurr(sum + 2, goal) + recurr(sum + 3, goal);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cout << recurr(0, n) << '\n';
	}

	return 0;
}