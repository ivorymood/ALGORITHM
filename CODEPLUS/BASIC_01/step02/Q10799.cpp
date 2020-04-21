//https://www.acmicpc.net/problem/10799
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input;
	getline(cin, input);

	stack<int> s;

	int answer = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			s.push(i);
		}
		else
		{
			// stack top의 인덱스와 1차이 나면 레이저.
			if ((i - s.top()) == 1)
			{
				s.pop();
				answer += s.size();
			}
			else
			{
				s.pop();
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}