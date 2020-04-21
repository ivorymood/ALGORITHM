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
	
	// 입력. 난쟁이 키 총합 계산
	int sum = 0;
	for (int i = 0; i < dwarfNum; i++)
	{
		cin >> dwarf[i];
		sum += dwarf[i];
	}

	// 오름차순 정렬
	sort(dwarf, dwarf + dwarfNum);

	for (int i = 0; i < dwarfNum; i++)
	{
		for (int j = i + 1; j < dwarfNum; j++)
		{
			// 총합 - 난쟁이키 2명 = 100 일때 출력 후 종료.
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