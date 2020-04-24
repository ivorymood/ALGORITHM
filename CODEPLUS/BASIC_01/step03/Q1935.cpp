//https://www.acmicpc.net/problem/1935
#include <iostream>
#include <stack>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int n;
	cin >> n;
	string postfix;
	cin >> postfix;

	int num[26];
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	// 후위 표기식 계산
	stack<double> s;
	for (char ch : postfix)
	{
		if ('A' <= ch && ch <= 'Z')
		{
			s.push(num[ch - 'A']);
		}
		else
		{
			double T = s.top();
			s.pop();
			double F = s.top();
			s.pop();

			switch (ch)
			{
			case '*': 
				s.push(F * T);
				break;
			case '/':
				s.push(F / T);
				break;
			case '+':
				s.push(F + T);
				break;
			case '-':
				s.push(F - T);
				break;
			}
		}
	}

	// 출력
	cout << fixed << setprecision(2) << s.top() << '\n';

	return 0;
}