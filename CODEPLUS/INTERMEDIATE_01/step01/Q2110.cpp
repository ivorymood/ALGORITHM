//https://www.acmicpc.net/problem/2110
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 라우터를 거리가 서로 min_gap 이상으로 설치할 때의 개수 구하기
int count_routers(vector<int> &houses, int min_gap)
{
	int last = houses[0];
	int cnt = 1;

	for (int i = 1; i < houses.size(); ++i)
	{
		if (houses[i] - last >= min_gap)
		{
			++cnt;
			last = houses[i];
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N, C;
	cin >> N >> C;
	vector<int> houses(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> houses[i];
	}

	// 이분탐색을 위한 정렬
	sort(houses.begin(), houses.end());

	// 이분탐색
	int left = 1;
	int right = houses.back() - houses.front();
	int answer = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt =  count_routers(houses, mid);

		/*
			최소간격이 mid일때 설치개수가 C이상이면, 
			간격을 더 늘릴 수 있는지 확인한다
		*/
		if (cnt >= C)
		{
			answer = max(mid, answer);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << answer;

	return 0;
}