//https://www.acmicpc.net/problem/16194
#include <iostream>
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
	vector<int> min_cost(n + 1);
	
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
		// 값을 아직 구하지 않았다는 뜻
		min_cost[i] = -1;
	}

	// 점화식 : D[n] = min(D[n - i] + P[i])
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// 문제에서 카드값은 1 ≤ Pi ≤ 10,000 이므로, 
			// (min_cost == 0) 여부를 기준으로 구분해도 상관없다
			if (min_cost[i] < 0 || min_cost[i] > min_cost[i - j] + cost[j])
			{
				min_cost[i] = min_cost[i - j] + cost[j];
			}
		}
	}

	cout << min_cost[n];

	return 0;
}