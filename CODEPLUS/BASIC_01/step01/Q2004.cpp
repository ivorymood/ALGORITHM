//https://www.acmicpc.net/problem/2004
#include <iostream>
#include <algorithm>

using namespace std;

// num! ���丮�󿡼� div ���� ���ϱ�
int get_factorial_div_cnt(int num, int div)
{
	int cnt = 0;
	for (long long i = div; num / i >= 1; i *= div)
	{
		cnt += num / i;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	// nCm ���տ����� �μ� 2�� 5 �� � ���� ������ �� ū�� �� �� ����.
	// ���� ��� �� �� ���� ���� ������ 0�� ������ ����. 
	int cnt_2 = get_factorial_div_cnt(n, 2) - get_factorial_div_cnt(m, 2) - get_factorial_div_cnt(n - m, 2);
	int cnt_5 = get_factorial_div_cnt(n, 5) - get_factorial_div_cnt(m, 5) - get_factorial_div_cnt(n - m, 5);

	cout << min(cnt_2, cnt_5);

	return 0;
}