//https://www.acmicpc.net/problem/2109
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct lec {
	int d_day, pay;
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	int today = 0;
	vector<lec> lectures(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> lectures[i].pay >> lectures[i].d_day;
		today = max(lectures[i].d_day, today);
	}

	// 날짜 내림차순으로 강연일정 정렬
	sort(lectures.begin(), lectures.end(), [](lec &A, lec &B) {
		return A.d_day > B.d_day;
		});


	int sum = 0;
	int l_idx = 0;
	priority_queue<int> q;

	// 1. 강연 일정의 마지막 날부터 강연을 선택해나간다.
	while (today)
	{
		// 2. d_day가 오늘인 강의는 우선순위 큐(선택가능한 일정들)에 push한다
		while (l_idx < N && lectures[l_idx].d_day == today)
		{
			q.push(lectures[l_idx++].pay);
		}

		// 3. 큐의 top은 선택가능한 가장 pay가 높은 일정이므로, 선택하고 pop한다.
		if (!q.empty())
		{
			sum += q.top();
			q.pop();
		}
		
		--today;
	}

	cout << sum;

	return 0;
}