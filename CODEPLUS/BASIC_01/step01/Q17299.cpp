//https://www.acmicpc.net/problem/17299
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 1000000;

	// �Է�, ����Ƚ�� F���� �����
	int n;
	cin >> n;
	vector<int> input(n);
	vector<int> F(MAX + 1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		F[input[i]]++;
	}

	// ���� : ����ū���� �Ǵ� ��
	stack<int> s;
	vector<int> ngf(n);
	for (int i = n - 1; i >= 0; i--)
	{
		// top�� input[i]�� ����ū���� �ƴϸ� stack pop
		while (!s.empty() && F[input[i]] >= F[input[s.top()]])
		{
			s.pop();
		}

		// ������ ����� : input[i]�� ����ū���� ����
		if (s.empty())
		{
			ngf[i] = -1;
		}
		// top�� input[i]�� ����ū��
		else
		{
			ngf[i] = input[s.top()];
		}

		s.push(i);
	}

	for (int i = 0; i < n; i++)
	{
		cout << ngf[i] << ' ';
	}

	return 0;
}