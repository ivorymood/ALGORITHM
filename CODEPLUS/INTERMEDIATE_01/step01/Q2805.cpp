//https://www.acmicpc.net/problem/2805
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// limit높으로 자르고 남은 길이 합 구하기
long long get_cut_off_sum(vector<int> &trees, long long limit)
{
	long long left = 0;
	for (int tree : trees)
	{
		if (tree - limit > 0)
		{
			left += tree - limit;
		}
	}
	return left;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	// 입력
	int N, M;
	cin >> N >> M;
	vector<int> trees(N);
	int max_tree = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> trees[i];
		if (max_tree < trees[i])
		{
			max_tree = trees[i];
		}
	}

	// 이분탐색
	long long answer = 0;
	long long left = 0;
	long long right = max_tree;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long sum = get_cut_off_sum(trees, mid);

		// 자른 합이 M보다 크거나 같다면 더 높이 자를 수 있는지 확인한다
		if (sum >= M)
		{
			// 자를 수 있는 최대 높이 갱신
			answer = max(mid, answer);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	// 출력
	cout << answer;

	return 0;
}