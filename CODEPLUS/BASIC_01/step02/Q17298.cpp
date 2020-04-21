//https://www.acmicpc.net/problem/17298
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	// 스택: 오큰수를 아직 찾지 못한 수
	stack<int> yet;
	yet.push(0);

	// 오큰수 찾기
	vector<int> nge(n);
	for (int i = 1; i < n; i++)
	{
		// input[i]가 top의 오큰수이면
		while (!yet.empty() && input[yet.top()] < input[i])
		{
			nge[yet.top()] = input[i];
			yet.pop();
		}
		yet.push(i);
	}

	// 오큰수를 찾지 못한 수 처리
	while (!yet.empty())
	{
		nge[yet.top()] = -1;
		yet.pop();
	}

	// 출력
	for (int i = 0; i < n; i++)
	{
		cout << nge[i] << ' ';
	}

	return 0;
}