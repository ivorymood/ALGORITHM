//https://www.acmicpc.net/problem/17299
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 1000000;

	// 입력, 등장횟수 F벡터 만들기
	int n;
	cin >> n;
	vector<int> input(n);
	vector<int> F(MAX + 1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		F[input[i]]++;
	}

	// 스택 : 오등큰수가 되는 수
	stack<int> s;
	vector<int> ngf(n);
	for (int i = n - 1; i >= 0; i--)
	{
		// top이 input[i]의 오등큰수가 아니면 stack pop
		while (!s.empty() && F[input[i]] >= F[input[s.top()]])
		{
			s.pop();
		}

		// 스택이 비었다 : input[i]의 오등큰수가 없음
		if (s.empty())
		{
			ngf[i] = -1;
		}
		// top이 input[i]의 오등큰수
		else
		{
			ngf[i] = input[s.top()];
		}

		s.push(i);
	}

	for (int i = 0; i < n; i++)
	{
		cout << ngf[i] << ' ';
	}

	return 0;
}