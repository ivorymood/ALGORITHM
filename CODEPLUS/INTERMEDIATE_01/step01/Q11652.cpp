//https://www.acmicpc.net/problem/11652
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
	vector<long long> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	// 오름차순 정렬
	sort(v.begin(), v.end());


	int max_cnt = 1;
	int last_cnt = 1;
	long long num = v[0];

	// 직전 숫자와 비교하여 같은 숫자들 개수 카운팅
	for (int i = 1; i < N; ++i)
	{
		if (v[i - 1] == v[i])
		{
			++last_cnt;
		}
		else
		{
			last_cnt = 1;
		}

		// max_cnt보다 개수가 많으면 num갱신
		if (max_cnt < last_cnt)
		{
			max_cnt = last_cnt;
			num = v[i];
		}
	}

	cout << num;

	return 0;
}