//https://www.acmicpc.net/problem/11055
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	/*
		점화식 :
		D[i] = max(D[k]) + a[i] (단, 0 <= k < i, a[k] < a[i])
	*/
	vector<int> max_sum(n);
	for (int i = 0; i < n; i++)
	{
		// a[i]가 부분증가수열 1번째일 경우 처리
		max_sum[i] = input[i];
		for (int j = 0; j < i; j++)
		{
			if (input[j] < input[i] && max_sum[j] + input[i] > max_sum[i])
			{
				max_sum[i] = max_sum[j] + input[i];
			}
		}
	}

	// D[i] 최대값 출력
	cout << *max_element(max_sum.begin(), max_sum.end());

	return 0;
}