//https://www.acmicpc.net/problem/11651
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2번째 요소 오름차순, 1번째 요소 오름차순으로 정렬
bool compare(pair<int, int> &A, pair<int, int> &B)
{
	if (A.second != B.second)
	{
		return A.second < B.second;
	}
	return A.first < B.first;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}

	// compare 기준으로 정렬
	sort(v.begin(), v.end(), compare);

	// 출력
	for (int i = 0; i < N; ++i)
	{
		cout << v[i].first << ' ' << v[i].second << '\n';
	}

	return 0;
}