//https://www.acmicpc.net/problem/1931
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct conf {
	int start, end;
};

bool compare(conf a, conf b) {
	if (a.end != b.end)
	{
		return a.end < b.end;
	}
	return a.start < b.start;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<conf> confs(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> confs[i].start >> confs[i].end;
	}

	// end가 빠른 순, start가 빠른 순으로 confs벡터 정렬
	sort(confs.begin(), confs.end(), compare);

	int now = 0, cnt = 0;
	for (int i = 0; i < confs.size(); ++i)
	{
		// 현재 <= 회의 start 시각일 때 
		// : 현재시각을 회의 끝시각으로 바꾸고 카운팅
		if (now <= confs[i].start)
		{
			now = confs[i].end;
			++cnt;
		}
	}

	cout << cnt;

	return 0;
}