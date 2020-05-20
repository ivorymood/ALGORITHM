//https://www.acmicpc.net/problem/6603
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 6;

void dfs(vector<int>& num, vector<int>& lotto, int index, int depth)
{
	// 6�ڸ��� �ϼ��Ǹ� ���
	if (depth == MAX)
	{
		for (int i = 0; i < MAX; ++i)
		{
			cout << lotto[i] << ' ';
		}
		cout << '\n';
		return;
	}
	// 6�ڸ��� �ϼ��Ǳ� ���� index�� ������ �Ѿ���� ���
	else if (index == num.size())
	{
		return;
	}

	lotto[depth] = num[index];

	// num[index]�� �����ϴ� ���
	dfs(num, lotto, index + 1, depth + 1);

	// num[index]�� �������� �ʴ� ���
	dfs(num, lotto, index + 1, depth);
}

int main()
{
	while (true)
	{
		// �Է�
		int k;
		cin >> k;
		if (k == 0)
		{
			break;
		}
		vector<int> num(k);
		for (int i = 0; i < k; ++i)
		{
			cin >> num[i];
		}

		// dfs - ��Ʈ��ŷ���� ���� ����
		vector<int> lotto(MAX);
		dfs(num, lotto, 0, 0);

		cout << '\n';
	}

	return 0;
}