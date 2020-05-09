//https://www.acmicpc.net/problem/15663
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 8;

int numbers[MAX];
int output[MAX];
int cnt[MAX];

void dfs(int N, int M, int depth)
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
		오름차순, 중복 허용X
		한번 숫자를 쓸 때마다 개수 - 1
		아직 숫자를 꺼내 쓸 수 있으면 선택 가능.
	*/
	for (int i = 0; i < N; ++i)
	{
		if (cnt[i] > 0)
		{
			--cnt[i];
			output[depth] = numbers[i];
			dfs(N, M, depth + 1);
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
	int tmp[MAX];

	for (int i = 0; i < N; ++i)
	{
		cin >> tmp[i];
	}
	
	// 오름차순 정렬
	sort(tmp, tmp + N);

	// 각 숫자의 개수를 저장한 cnt배열 만들기
	// numbers배열에 중복 제거한 숫자들 저장하기
	int num = -1;
	int idx = 0;
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

	// 중복 제거한 숫자 개수 중에서 M개 뽑기
	dfs(idx, M, 0);

	return 0;
}