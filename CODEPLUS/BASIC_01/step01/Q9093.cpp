//https://www.acmicpc.net/problem/9093
#pragma warning(disable:4996)
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	// iostream ����� �ӵ� ���
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore(1, '\n');	// input stream ����ֱ� : 1��° ���� ������ŭ && 2��° ���ڱ���

	while (n--)
	{
		// �� �پ� �Է¹ް�, ���๮�� ����� ���� '\n' �߰�
		string line;
		getline(cin, line);
		line += '\n';

		stack<char> s;
		for (char c : line)
		{
			// ' ' �Ǵ� '\n'�� ���� ���� ����
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

			// �Ϲ� ���ڴ� ���� �߰�
			s.push(c);
		}
	}

	return 0;
}