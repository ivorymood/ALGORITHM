//https://www.acmicpc.net/problem/16198
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_sum;

void go(vector<int>& nrg, int sum)
{
	// 구슬이 2개만 남으면 최대합계 갱신 후 종료
	int N = nrg.size();
	if (N == 2)
	{
		max_sum = max(sum, max_sum);
		return;
	}

	// new_nrg에 i번째를 제외한 나머지 구슬 값 넣기
	vector<int> new_nrg(N - 1);
	for (int i = 1; i < N - 1; ++i)
	{
		int idx = 0;
		for (int j = 0; j < N; ++j)
		{
			if (j == i)
			{
				continue;
			}
			new_nrg[idx++] = nrg[j];
		}

		// 새로운 구슬벡터와 sum + nrg[i - 1] * nrg[i + 1]값으로 재귀함수 호출
		go(new_nrg, sum + nrg[i - 1] * nrg[i + 1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<int> nrg(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nrg[i];
	}

	/*
		구슬이 2개 남을때까지 x번째 구슬을 지우면서 
		x - 1번째 * x + 1번째 값의 합계를 구하는 재귀함수
	*/
	go(nrg, 0);

	// 출력
	cout << max_sum;

	return 0;
}