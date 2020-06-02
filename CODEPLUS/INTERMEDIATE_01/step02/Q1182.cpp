//https://www.acmicpc.net/problem/1182
#include <iostream>
#include <vector>

using namespace std;

int cnt;

void dfs(vector<int> &nums, vector<bool> &check, int S, int idx)
{
	// 숫자열의 끝에 도착하면
	if (idx == nums.size())
	{
		// true 체크된 숫자들 (= 부분집합) 합계 구하기
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (check[i])
			{
				sum += nums[i];
			}
		}

		// 합계가 S이면 카운팅
		if (sum == S)
		{
			++cnt;
		}

		return;
	}

	// idx번째 숫자를 선택할 때
	check[idx] = true;
	dfs(nums, check, S, idx + 1);
	check[idx] = false;

	// idx번째 숫자를 선택하지 않을 때
	dfs(nums, check, S, idx + 1);
}

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

	// 백트랙킹으로 부분집합의 합계 구하기
	vector<bool> check(N);
	dfs(nums, check, S, 0);

	// S가 0일 경우, 아무것도 선택하지 않는 경우도 카운팅 되므로 -1
	if (S == 0) 
	{
		--cnt;
	}

	// 출력
	cout << cnt;

	return 0;
}