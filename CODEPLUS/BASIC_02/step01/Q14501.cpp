//https://www.acmicpc.net/problem/14501
#include <iostream>
#include <vector>

using namespace std;

int max_sum;

void dfs(vector<int> &dates, vector<int> &money, int sum, int index)
{
	// 일의 종료 시점이 주어진 날짜보다 클때
	if (index > dates.size())
	{
		return;
	}
	// 주어진 날짜에 일을 종료할 수 있을 때
	else if (index == dates.size())
	{
		if (max_sum < sum)
		{
			max_sum = sum;
		}
		return;
	}

	// index일에 들어온 일감을 선택할 때
	dfs(dates, money, sum + money[index], index + dates[index]);

	// index일에 들어온 일감을 선택하지 않을 때
	dfs(dates, money, sum, index + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;

	vector<int> dates(N);
	vector<int> money(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> dates[i] >> money[i];
	}
	
	// dfs - 백트랙킹으로 일감 조합
	dfs(dates, money, 0, 0);

	cout << max_sum;

	return 0;
}