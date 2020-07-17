//https://www.acmicpc.net/problem/16968
#include <iostream>

using namespace std;

int dfs(string &format, int idx, int bf)
{
	if (format.size() == idx)
	{
		return 1;
	}

	/*
		���� ���� : a ~ z
		���� ���� : 0 ~ 9
	*/
	int strt = (format[idx] == 'c' ? 'a' : '0');
	int end = (format[idx] == 'c' ? 'z' : '9');

	int total = 0;
	for (char i = strt; i <= end; ++i)
	{
		// �չ��ڿ� �ߺ����� ������ ����� �� ī����
		if (i != bf)
		{
			total += dfs(format, idx + 1, i);
		}
	}
	return total;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	string format;
	cin >> format;

	// dfs ���Ʈ������ ������ ��� ����� �� ���ϱ�
	cout << dfs(format, 0, ' ');


	return 0;
}