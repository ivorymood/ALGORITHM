//https://www.acmicpc.net/problem/15658
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// 답안의 범위가 -10억 ~ 10억
int max_num = numeric_limits<int>::min();
int min_num = numeric_limits<int>::max();

// 주어진 연산자 인덱스로 계산 
int calc(int op, int num1, int num2) 
{ 
	if (op == 0) 
	{ 
		return num1 + num2; 
	} 
	else if (op == 1) 
	{ 
		return num1 - num2; 
	} 
	else if (op == 2) 
	{ 
		return num1 * num2; 
	} 
	else if (op == 3) 
	{ 
		return num1 / num2; 
	} 
	return 0; 
}

void dfs(vector<int> &nums, vector<int> &ops, int res, int depth)
{
	if (depth == nums.size())
	{
		max_num = max(max_num, res); 
		min_num = min(min_num, res);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		// 연산 가능한 횟수가 남아있으면
		if (ops[i] > 0)
		{
			--ops[i];
			// 이전 결과와 현재숫자를 연산한 값으로 dfs함수 재귀호출
			dfs(nums, ops, calc(i, res, nums[depth]), depth + 1);
			++ops[i];
		}
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
	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	vector<int> ops(4);
	for (int i = 0; i < 4; ++i)
	{
		cin >> ops[i];
	}
	
	// 백트랙킹으로 가능한 모든 수를 구해서 최대값/최소값 결정하기
	dfs(nums, ops, nums[0], 1);

	// 출력 
	cout << max_num << '\n'; 
	cout << min_num << '\n';

	return 0;
}