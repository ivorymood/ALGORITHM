//https://www.acmicpc.net/problem/10610
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력 - 숫자가 들어온 횟수를 nums벡터에 카운팅
	vector<int> nums(10);
	char c;
	int sum = 0;
	while ((c = getchar()) != '\n')
	{
		++nums[c - '0'];
		sum += c - '0';
	}

	// 합이 3으로 나누어 떨어지지 않거나, 0이 하나도 없으면 실패
	if (sum % 3 != 0 || nums[0] == 0)
	{
		cout << -1;
	}
	else
	{
		// 큰 숫자부터 들어온 횟수만큼 출력
		int idx = 9;
		while (idx >= 0)
		{
			while (nums[idx]-- > 0)
			{
				cout << idx;
			}
			--idx;
		}
	}

	return 0;
}