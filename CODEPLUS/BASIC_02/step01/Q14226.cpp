//https://www.acmicpc.net/problem/14226
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000;
int time[MAX + 1][MAX + 1];

void check(queue<pair<int, int>> &q, int S, int next, int next_clip, int now)
{
	// 범위를 벗어나거나, 이미 값이 존재하는 경우 종료
	if (next < 0 || next > S || time[next][next_clip] != 0)
	{
		return;
	}
	// 연산횟수 + 1
	time[next][next_clip] = now + 1;
	// 큐에 <연산 후 화면문자 개수, 클립보드 문자 개수> push
	q.push(make_pair(next, next_clip));
}

// 너비우선 탐색으로 S에 도착할 때까지 연산횟수를 time 배열에 저장해나간다.
int bfs(int S)
{
	queue<pair<int, int>> q;
	q.push({ 1, 0 });

	while (!q.empty())
	{
		int now = q.front().first;
		int bf_clip = q.front().second;
		q.pop();

		// 화면 문자개수가 S개가 되면 연산횟수 반환 및 종료
		if (now == S)
		{
			return time[now][bf_clip];
		}

		/*
			복사     : <현재 화면문자       , 현재 화면문자>
			붙여넣기 : <현재 화면문자 + 클립, 클립>
			삭제     : <현재 화면문자 -1    , 클립>
		*/
		check(q, S, now          , now    , time[now][bf_clip]);
		check(q, S, now + bf_clip, bf_clip, time[now][bf_clip]);
		check(q, S, now - 1      , bf_clip, time[now][bf_clip]);
	}

	return S + 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int S;
	cin >> S;
	cout << bfs(S);

	return 0;
}