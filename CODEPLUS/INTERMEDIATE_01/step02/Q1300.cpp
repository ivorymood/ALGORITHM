//https://www.acmicpc.net/problem/1300
#include <iostream>
#include <algorithm>

using namespace std;

// 두 수의 곱이 int범위를 넘을 수 있기 때문에 long long 형으로 선언
long long N, K;

// num보다 더 작은 수의 개수 구하기
long long count_smaller(long long num)
{
	// 두 수가 [1, N] 범위에 있을 동안 반복문
	long long cnt = 0;
	for (long long i = 1, j = N; i <= N && j > 0; ++i)
	{
		// 두 수이 곱이 num보다 크면 --j
		while (i * j >= num)
		{
			--j;
		}

		if (j > 0)
		{
			cnt += j;
		}
	}

	return cnt;
}

// 이분탐색으로 K번째 수 구하기
long long binary_search(long long left, long long right)
{
	long long ans = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;

		// mid보다 더 작은 수의 개수가 K보다 작으면 
		if (count_smaller(mid) < K)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}

	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> N >> K;

	// 이분탐색으로 K번째 수 구하기
	cout << binary_search(0, N * N);


	return 0;
}