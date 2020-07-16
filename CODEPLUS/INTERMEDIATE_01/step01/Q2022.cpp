//https://www.acmicpc.net/problem/2022
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// 계산시 오차 범위
const double EPS = 1e-6;
double x, y, c;

bool check(double w)
{
	// 피타고라스 법칙
	double h_L = sqrt(x * x - w * w);
	double h_R = sqrt(y * y - w * w);

	// 닮음비 이용하여 tmp_c 계산
	double tmp_c = (h_L * h_R) / (h_L + h_R);

	// tmp_c가 주어진 c값보다 같거나 크다면 true
	return tmp_c >= c;
}

double binary_search(double left, double right)
{
	// left < right 인 동안 이분탐색으로 두 빌딩의 떨어진 거리 찾기
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

	// 이분탐색으로 두 빌딩의 떨어진 거리를 찾고, 소수점 3째 자리까지 출력
	printf("%.3lf\n", binary_search(0, min(x, y)));

	return 0;
}