//https://www.acmicpc.net/problem/6603
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> &nums, vector<bool> &check, int cnt, int depth)
{
	// 선택한 개수가 6개가 되었을 때 출력
	if (cnt == 6)
	{
		for (int i = 0; i < nums.size(); ++i)
		{
			if (check[i])
			{
				cout << nums[i] << ' ';
			}
		}
		cout << '\n';

		return;
	}
	// 6개를 선택하기 전에 숫자열이 끝났을 때
	else if (depth == nums.size())
	{
		return;
	}

	// depth 번째 숫자를 선택하는 경우
	check[depth] = true;
	dfs(nums, check, cnt + 1, depth + 1);
	check[depth] = false;

	// depth 번째 숫자를 선택하지 않는 경우
	dfs(nums, check, cnt, depth + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		// 입력
		int N;
		cin >> N;
		if (N == 0)
		{
			break;
		}
		vector<int> nums(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> nums[i];
		}

		// 선택 여부를 체크할 bool 벡터
		vector<bool> check(N);
		// 백트랙킹으로 6개 숫자 선택
		dfs(nums, check, 0, 0);
		cout << '\n';
	}

	return 0;
}