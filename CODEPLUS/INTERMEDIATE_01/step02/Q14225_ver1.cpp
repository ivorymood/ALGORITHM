//https://www.acmicpc.net/problem/14225
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000 * 20;

void dfs(vector<int>& nums, vector<bool> &visit, int num, int idx)
{
	// 부분수열의 합계 num 방문체크 하기
	visit[num] = true;
	
	// 인덱스 범위를 넘으면 종료
	if (idx == nums.size())
	{
		return;
	}
	
	// idx번째 수를 포함하지 않는 경우
	dfs(nums, visit, num, idx + 1);

	// idx번째 수를 포함하는 경우
	dfs(nums, visit, num + nums[idx], idx + 1);
}

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

	// 백트랙킹으로 가능한 부분집합의 합 모두 구하기
	vector<bool> visit(MAX + 1);
	dfs(nums, visit, 0, 0);
	
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