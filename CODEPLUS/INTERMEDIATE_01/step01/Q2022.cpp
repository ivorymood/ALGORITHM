//https://www.acmicpc.net/problem/2022
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// ���� ���� ����
const double EPS = 1e-6;
double x, y, c;

bool check(double w)
{
	// ��Ÿ��� ��Ģ
	double h_L = sqrt(x * x - w * w);
	double h_R = sqrt(y * y - w * w);

	// ������ �̿��Ͽ� tmp_c ���
	double tmp_c = (h_L * h_R) / (h_L + h_R);

	// tmp_c�� �־��� c������ ���ų� ũ�ٸ� true
	return tmp_c >= c;
}

double binary_search(double left, double right)
{
	// left < right �� ���� �̺�Ž������ �� ������ ������ �Ÿ� ã��
	while (abs(right - left) > EPS)
	{
		double mid = (left + right) / 2.0;

		if (check(mid))
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> x >> y >> c;

	// �̺�Ž������ �� ������ ������ �Ÿ��� ã��, �Ҽ��� 3° �ڸ����� ���
	printf("%.3lf\n", binary_search(0, min(x, y)));

	return 0;
}