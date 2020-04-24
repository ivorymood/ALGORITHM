//https://www.acmicpc.net/problem/1918
#include <iostream>
#include <stack>

using namespace std;

// �켱���� : ���� Ŭ���� �켱������ ����.
int prior(char ch)
{
	if (ch == '(')
	{
		return 0;
	}
	else if (ch == '+' || ch == '-')
	{
		return 1;
	}
	return 2;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ���� ǥ��� �Է�
	string infix;
	cin >> infix;

	char ans[101];
	int ap = 0;

	// ���� ǥ��� �����
	stack<char> op;
	for (char ch : infix)
	{
		// �ǿ����� -> �״�� ���
		if ('A' <= ch && ch <= 'Z')
		{
			ans[ap++] = ch;
		}
		// ������ -> �켱������ ���� ���
		else
		{
			// '(' : �켱������ ���� �����Ƿ�, ���� ó�����ش�. push only
			if (ch == '(')
			{
				op.push(ch);
			}
			// ')' : '('�� ���������� ���
			else if (ch == ')')
			{
				while (!op.empty())
				{
					char top = op.top();
					op.pop();
					if (top == '(')
					{
						break;
					}
					ans[ap++] = top;
				}
			}
			// �� �� ������ : �켱������ ���� �����ڵ��� ��� ���� ���
			else
			{
				while (!op.empty() && prior(op.top()) >= prior(ch))
				{
					ans[ap++] = op.top();
					op.pop();
				}
				op.push(ch);
			}
		}
	}

	while (!op.empty())
	{
		ans[ap++] = op.top();
		op.pop();
	}

	ans[ap] = '\0';
	cout << ans;

	return 0;
}