//https://www.acmicpc.net/problem/12015
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	/*
		���� �� �����ϴ� ���� �����
		���ʿ� �� ū ���� ������ ���ο� ���� LIS���� �ڿ� �̾���̰�
		�� ū���� �ִٸ� �� �ڸ��� ���ο� ������ ��ü�Ѵ�.
	*/
	vector<int> LIS;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;

		// LIS���Ϳ��� num���� ���ų� ū ���� ��ġ ã��
		auto it = lower_bound(LIS.begin(), LIS.end(), num);

		// num���� ���ų� ū ���� ���ٸ� : LIS�� ���� num push
		if (it == LIS.end())
		{
			LIS.push_back(num);
		}
		// num���� ���ų� ū ���� ������ : num���� ��ü
 		else
		{
			*it = num;
		}
	}

	cout << LIS.size();

	return 0;
}