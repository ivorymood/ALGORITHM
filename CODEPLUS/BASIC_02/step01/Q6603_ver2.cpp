//https://www.acmicpc.net/problem/6603
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 6;

void dfs(vector<int>& num, vector<int>& lotto, int index, int depth)
{
	// 6자리가 완성되면 출력
	if (depth == MAX)
	{
		for (int i = 0; i < MAX; ++i)
		{
			cout << lotto[i] << ' ';
		}
		cout << '\n';
		return;
	}
	// 6자리가 완성되기 전에 index가 범위를 넘어버린 경우
	else if (index == num.size())
	{
		return;
	}

	lotto[depth] = num[index];

	// num[index]를 선택하는 경우
	dfs(num, lotto, index + 1, depth + 1);

	// num[index]를 선택하지 않는 경우
	dfs(num, lotto, index + 1, depth);
}

int main()
{
	while (true)
	{
		// 입력
		int k;
		cin >> k;
		if (k == 0)
		{
			break;
		}
		vector<int> num(k);
		for (int i = 0; i < k; ++i)
		{
			cin >> num[i];
		}

		// dfs - 백트랙킹으로 숫자 조합
		vector<int> lotto(MAX);
		dfs(num, lotto, 0, 0);

		cout << '\n';
	}

	return 0;
}