//https://www.acmicpc.net/problem/2751
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; ++i)
	{
		cout << v[i] << '\n';
	}

	return 0;
}