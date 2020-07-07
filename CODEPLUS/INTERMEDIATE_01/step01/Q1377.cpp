//https://www.acmicpc.net/problem/1377
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
	int N;
	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; ++i)
	{
		// 입력된 순서 저장
		v[i].second = i;
		cin >> v[i].first;
	}

	// 정렬
	sort(v.begin(), v.end());

	// 입력된 순서와 정렬된 순서 비교
	int max_moved = 0;
	for (int i = 0; i < N; ++i)
	{
		// 뒤에서 앞으로 이동한 최대 칸수 구하기
		if (max_moved < v[i].second - i)
		{
			max_moved = v[i].second - i;
		}
	}

	// 최대로 이동한 횟수 + 1 : 몇회만에 버블정렬이 되었는지
	cout << max_moved + 1;

	return 0;
}