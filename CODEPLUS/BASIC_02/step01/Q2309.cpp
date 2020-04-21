//https://www.acmicpc.net/problem/2309
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int dwarfNum = 9;
	int dwarf[dwarfNum];
	
	// �Է�. ������ Ű ���� ���
	int sum = 0;
	for (int i = 0; i < dwarfNum; i++)
	{
		cin >> dwarf[i];
		sum += dwarf[i];
	}

	// �������� ����
	sort(dwarf, dwarf + dwarfNum);

	for (int i = 0; i < dwarfNum; i++)
	{
		for (int j = i + 1; j < dwarfNum; j++)
		{
			// ���� - ������Ű 2�� = 100 �϶� ��� �� ����.
			if (sum - (dwarf[i] + dwarf[j]) == 100)
			{
				for (int k = 0; k < dwarfNum; k++)
				{
					if (k == i || k == j)
					{
						continue;
					}
					cout << dwarf[k] << '\n';
				}
				return 0;
			}
		}
	}

	return 0;
}