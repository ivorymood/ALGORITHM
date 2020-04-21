//https://www.acmicpc.net/problem/17413
#include <iostream>
#include <string>
#include <stack>

using namespace std;

void print_stack(stack<char> &s)
{
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input;
	getline(cin, input);

	stack<char> s;
	bool is_in_tag = false;

	for (int i = 0; i < input.size(); i++)
	{
		// �����±׿� ���� ���� �÷��� ���
		if (input[i] == '<')
		{
			print_stack(s);
			is_in_tag = true;
		}

		if (is_in_tag)
		{
			cout << input[i];
		}
		else
		{
			// ' '���� ���� ���� �ش� ���� ���
			if (input[i] == ' ')
			{
				print_stack(s);
				cout << input[i];
			}
			// �±� ���� ���ڴ� ���� push
			else
			{
				s.push(input[i]);
			}
		}

		// �ݴ� �±׿� �÷��� ���
		if (input[i] == '>')
		{
			is_in_tag = false;
		}
	}
	print_stack(s);

	return 0;
}