//https://www.acmicpc.net/problem/11052
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> cost(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}

	// 점화식 : D[n] = max(D[n - i] + P[i])
	vector<int> max_cost(n + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			max_cost[i] = max(max_cost[i], max_cost[i - j] + cost[j]);
		}
	}

	cout << max_cost[n];

	return 0;
}