//https://www.acmicpc.net/problem/14225
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000 * 20;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	// 비트마스크로 가능한 부분집합의 합 모두 구하기
	vector<bool> visit(MAX + 1);
	for (int i = 1; i < (1 << N); ++i)
	{
		int sum = 0;
		for (int j = 0; j < N; ++j)
		{
			if ((1 << j) & i)
			{
				sum += nums[j];
			}
		}
		visit[sum] = true;
	}

	// 방문 체크 되지 않은 수 출력
	for (int i = 1; i <= MAX; ++i)
	{
		if (!visit[i])
		{
			cout << i << '\n';
			break;
		}
	}

	return 0;
}