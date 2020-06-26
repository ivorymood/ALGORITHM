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



	/*
		각 그룹의 시작 인덱스를 저장할 strt_idx벡터
		
		ex) N = 8, M = 4, K = 3 이면 --> (1)(3 2)(5 4)(8 7 6) 형태로 
			최대 길이 K의 그룹 M개로 나누어 그 안에서 뒤집어준다.
	*/
	vector<int> strt_idx(M + 1);
	
	// 마지막 그룹의 끝 인덱스를 위해 N + 1 저장
	strt_idx[M] = N + 1;

	// 그룹중 하나는 반드시 K개가 되어야 한다
	N -= K;
	strt_idx[M - 1] = N + 1;

	// 나머지 그룹의 크기는 K를 넘지 않도록 적절히 분배
	for (int i = M - 2; i >= 0; --i)
	{
		int size = min(K, N / (i + 1));

		N -= size;
		strt_idx[i] = N + 1;

	}



	// strt_idx벡터의 2번째 요소부터 반복문
	for (int i = 1; i < strt_idx.size(); ++i)
	{
		// (i번째 그룹 요소 - 1)부터 (i번째 그룹요소) 까지 역순으로 출력
		for (int num = strt_idx[i] - 1; num >= strt_idx[i - 1]; --num)
		{
			cout << num << ' ';
		}
	}
		
	return 0;
}