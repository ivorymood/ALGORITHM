//https://www.acmicpc.net/problem/6603
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

		// ��ġ ������ ���� k������ bool ���� ����. 6�ڸ����� ���� true�� ������. 
		vector<bool> pos(k);
		for (int i = 0; i < 6; ++i)
		{
			pos[i] = true;
		}

		// �������� ��ġ �������, �ڸ����� true�� num[i]�� ���
		do
		{
			for (int i = 0; i < k; ++i)
			{
				if (pos[i])
				{
					cout << num[i] << ' ';
				}
			}
			cout << '\n';

		} while (prev_permutation(pos.begin(), pos.end()));

		cout << '\n';
	}

	return 0;
}