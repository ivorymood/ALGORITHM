//https://www.acmicpc.net/problem/1201
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
	int N, M, K;
	cin >> N >> M >> K;

	/*
		정답이 없는 경우
		1. 최대 부분 증가수열과 최대 부분 감소 수열은 하나의 원소만 공유한다.
		2. 비둘기집 원리 
		: N = M * K + 1이면 길이가 M + 1인 증가수열 또는 길이가 K + 1인 감소 수열을 만들 수 있다.
	*/
	if (N < M + K - 1 || N > M * K)
	{
		cout << -1;
		return 0;
	}

	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
	{
		nums[i] = i = 1;
	}

	/*
		ex) N = 8, M = 4, K = 3 이면 --> (1)(3 2)(5 4)(8 7 6) 형태로 
		최대 길이 K의 그룹 M개로 나누어 그 안에서 뒤집어준다.
	*/
	int g_strt = 0;
	for (int i = 1; i <= M; ++i)
	{
		// 각 그룹은 최소 1개, 최대 K개 요소를 가질 수 있다.
		int g_end = min(g_strt + K, N - M + i);

		// [g_strt, g_end)의 요소들을 뒤집기
		reverse(nums.begin() + g_strt, nums.begin() + g_end);

		// 다음 그룹 시작은 g_end부터
		g_strt = g_end;
	}

	// 출력
	for (int i = 0; i < N; ++i)
	{
		cout << nums[i];
	}

	return 0;
}