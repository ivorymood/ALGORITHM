//https://www.acmicpc.net/problem/9093
#pragma warning(disable:4996)
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	// iostream 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore(1, '\n');	// input stream 비워주기 : 1번째 인자 개수만큼 && 2번째 인자까지

	while (n--)
	{
		// 한 줄씩 입력받고, 개행문자 출력을 위해 '\n' 추가
		string line;
		getline(cin, line);
		line += '\n';

		stack<char> s;
		for (char c : line)
		{
			// ' ' 또는 '\n'이 오면 스택 비우기
			if (c == ' ' || c == '\n')
			{
				while (!s.empty())
				{
					cout << s.top();
					s.pop();
				}
				cout << c;
				continue;
			}

			// 일반 문자는 스택 추가
			s.push(c);
		}
	}

	return 0;
}