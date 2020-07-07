//https://www.acmicpc.net/problem/10816
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
	int N, M;
	cin >> N;
	vector<int> cards(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> cards[i];
	}

	// 이분탐색을 위한 오름차 정렬
	sort(cards.begin(), cards.end());

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int test;
		cin >> test;

		// test와 같은 요소들의 begin과 end 반복자 pair
		auto pair_it = equal_range(cards.begin(), cards.end(), test);

		// cards에 test값이 포함되어 있지 않다면 0, 포함되어 있으면 개수 출력
		if (pair_it.second - pair_it.first == 0)
		{
			cout << 0 << ' ';
		}
		else
		{
			cout << (pair_it.second - pair_it.first) << ' ';
		}
	}

	return 0;
}