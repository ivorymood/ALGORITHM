//https://www.acmicpc.net/problem/2089
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	// 0�ϰ�� ����ó��
	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	stack<int> s_mbin;
	while (n != 0)
	{
		int quot = n / -2;

		// �������� ���� ��
		if (n % -2 == 0)
		{
			s_mbin.push(0);
			n = quot;
		}
		// �������� ���� ��
		else
		{
			// ex) -13 / -2 = 6 ... 1 �ε�,
			//     -2 * (6 + 1) + 1 = -13 ó�� ���󺹱� �Ҷ� �� 1�� �� �ʿ��� ���
			if (n < 0)
			{
				n = quot + 1;
			}
			// ex) 7 / -2 = -3 ... 1 �ε�,
			//    -2 * -3 + 1 = 7�� ���
			else
			{
				n = quot;
			}
			s_mbin.push(1);
		}
	}

	while (!s_mbin.empty())
	{
		cout << s_mbin.top();
		s_mbin.pop();
	}

	return 0;
}