//https://www.acmicpc.net/problem/11052
#include <iostream>

using namespace std;

const int MAX = 1000;
int cost[MAX + 1];
int max_cost[MAX + 1];

// Á¡È­½Ä : D[n] = max(D[n - i] + P[i])
int get_max_cost(int n)
{
	if (max_cost[n] > 0)
	{
		return max_cost[n];
	}

	if (n <= 0)
	{
		return 0;
	}

	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp = get_max_cost(n - i) + cost[i];
		max = (max < temp) ? temp : max;
	}

	return max_cost[n] = max;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}
	
	get_max_cost(n);

	cout << max_cost[n];

	return 0;
}