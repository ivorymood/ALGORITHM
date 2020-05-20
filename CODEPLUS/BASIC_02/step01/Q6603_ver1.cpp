//https://www.acmicpc.net/problem/6603
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	while (true)
	{
		// 입력
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

		// 위치 정렬을 위해 k길이의 bool 벡터 생성. 6자리만의 값을 true로 가진다. 
		vector<bool> pos(k);
		for (int i = 0; i < 6; ++i)
		{
			pos[i] = true;
		}

		// 역사전순 위치 순서대로, 자릿값이 true인 num[i]를 출력
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