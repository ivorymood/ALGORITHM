//https://www.acmicpc.net/problem/9095
#include <iostream>

using namespace std;

int recurr(int sum, int goal)
{
	// 합이 목표 숫자보다 클때 : 불가능한 가짓수
	if (sum > goal)
	{
		return 0;
	}
	// 합 = 목표 숫자일때 : 가능한 가짓수
	else if (sum == goal)
	{
		return 1;
	}

	// (1, 2, 3)을 더해서 목표 숫자가 되는 가짓수 구하기
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