//https://www.acmicpc.net/problem/1406
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	// 입출력 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 문자열을 left 스택에 담기
	stack<char> left, right;
	string line;
	cin >> line;
	for (int i = 0; i < line.size(); i++)
	{
		left.push(line[i]);
	}
	int n;
	cin >> n;
	while (n--)
	{
		// 커서를 기준으로 '왼쪽'동작은 left스택에, '오른쪽'동작은 right스택에
		char cmd;
		cin >> cmd;

		switch (cmd)
		{
		case 'L':
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
			break;
		case 'D':
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
			break;
		case 'B':
			if (!left.empty())
			{
				left.pop();
			}
			break;
		case 'P':
			char c;
			cin >> c;
			left.push(c);
			break;
		}
	}
	// left스택 -> right스택 옮기기
	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}
	// right스택을 top에서부터 받아서 answer저장 & 출력
	string answer;
	while (!right.empty())
	{
		answer += right.top();
		right.pop();
	}
	cout << answer;
	return 0;
}