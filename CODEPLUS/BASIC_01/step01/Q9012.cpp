//https://www.acmicpc.net/problem/9012
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// ����� ���
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �׽�Ʈ Ƚ�� �Է¹ް� ���� ����
	int n;
	cin >> n;
	cin.ignore();

	while (n--)
	{
		string line;
		getline(cin, line);
		
		// '(' �� ')' �������̸� ���ϱ� 
		// '(' : +1
		// ')' : -1
		int sum = 0;
		for (char c : line)
		{
			
			if (c == '(')
			{
				sum++;
			}
			else if (c == ')')
			{
				sum--;
			}

			// �Է¹��� '('���� ')'�� ���� ��
			if (sum < 0)
			{
				break;
			}
		}

		// '(' �� ')' ������ �����ϸ� YES, �ƴϸ� NO ���
		cout << ((sum == 0) ? "YES" : "NO") << '\n';
	}
	return 0;
}