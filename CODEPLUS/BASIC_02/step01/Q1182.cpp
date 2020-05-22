//https://www.acmicpc.net/problem/1182
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N, S;
	cin >> N >> S;
	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	/*
		i : 부분집합 
		ex) 10101 : 1,3,5 번째 수를 포함하고 2,4번째 수는 포함하지 않는 부분집합 
	*/
	int cnt = 0;
	for (int i = 1; i < (1 << N); ++i)
	{
		// 현재 부분집합에 포함된 수의 합계 구하기
		int sum = 0;
		for (int j = 0; j < N; ++j)
		{
			if (i & (1 << j))
			{
				sum += nums[j];
			}
		}

		// 합계가 S와 일치하면 경우의 수 카운트
		if (sum == S)
		{
			++cnt;
		}
	}

	cout << cnt;

	return 0;
}