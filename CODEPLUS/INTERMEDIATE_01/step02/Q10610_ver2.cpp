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

	// �Է� - ���ڰ� ���� Ƚ���� nums���Ϳ� ī����
	vector<int> nums(10);
	char c;
	int sum = 0;
	while ((c = getchar()) != '\n')
	{
		++nums[c - '0'];
		sum += c - '0';
	}

	// ���� 3���� ������ �������� �ʰų�, 0�� �ϳ��� ������ ����
	if (sum % 3 != 0 || nums[0] == 0)
	{
		cout << -1;
	}
	else
	{
		// ū ���ں��� ���� Ƚ����ŭ ���
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