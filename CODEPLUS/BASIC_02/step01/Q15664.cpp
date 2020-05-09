//https://www.acmicpc.net/problem/15664
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 8;
int numbers[MAX];
int output[MAX];
int cnt[MAX];

void dfs(int N, int M, int depth, int start)
{
	if (depth == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << output[i] << ' ';
		}
		cout << '\n';

		return;
	}

	/* 
		비내림차순 --> 다음 숫자는 이번숫자 idx부터 조회 시작
		중복 허용X --> 한번 숫자를 쓸 때마다 개수 - 1 
		아직 숫자를 꺼내 쓸 수 있으면 선택 가능. 
	*/

	for (int i = start; i < N; ++i)
	{
		if (cnt[i] > 0)
		{
			--cnt[i];
			output[depth] = numbers[i];
			dfs(N, M, depth + 1, i);
			++cnt[i];
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	int tmp[MAX] = {0,};
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp[i];
	}

	sort(tmp, tmp + N);

	int num = -1;
	int idx = 0;

	// 각 숫자의 개수를 저장한 cnt배열 만들기 
	// numbers배열에 중복 제거한 숫자들 저장하기
	for (int i = 0; i < N; ++i)
	{
		if (num != tmp[i])
		{
			num = tmp[i];
			numbers[idx] = tmp[i];
			++cnt[idx];
			++idx;
		}
		else
		{
			++cnt[idx - 1];
		}
	}

	dfs(idx, M, 0, 0);

	return 0;
}