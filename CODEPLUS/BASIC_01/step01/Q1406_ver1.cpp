//https://www.acmicpc.net/problem/1406
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	// ����� ���
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// ���ڿ��� left ���ÿ� ���
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
		// Ŀ���� �������� '����'������ left���ÿ�, '������'������ right���ÿ�
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
	// left���� -> right���� �ű��
	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}
	// right������ top�������� �޾Ƽ� answer���� & ���
	string answer;
	while (!right.empty())
	{
		answer += right.top();
		right.pop();
	}
	cout << answer;
	return 0;
}