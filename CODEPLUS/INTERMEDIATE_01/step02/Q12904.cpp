//https://www.acmicpc.net/problem/12904
#include <iostream>
#include <algorithm>

using namespace std;

bool change(string &from, const string &to)
{
	// from ���ڿ��� to���ڿ��� ���̰� ������ ������
	while (from.length() > to.length())
	{
		// �� �ڰ� A�� : ���� 1 ����
		if (from.back() == 'A')
		{
			from.pop_back();
		}
		// �� �ڰ� B�� : ���� 2 ����
		else
		{
			from.pop_back();
			reverse(from.begin(), from.end());
		}
	}

	// �� ���ڿ��� ������ true
	return from.compare(to) == 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string to, from;
	cin >> to >> from;

	cout << change(from, to);

	return 0;
}