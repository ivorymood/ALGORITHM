//https://www.acmicpc.net/problem/2110
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ����͸� �Ÿ��� ���� min_gap �̻����� ��ġ�� ���� ���� ���ϱ�
int count_routers(vector<int> &houses, int min_gap)
{
	int last = houses[0];
	int cnt = 1;

	for (int i = 1; i < houses.size(); ++i)
	{
		if (houses[i] - last >= min_gap)
		{
			++cnt;
			last = houses[i];
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, C;
	cin >> N >> C;
	vector<int> houses(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> houses[i];
	}

	// �̺�Ž���� ���� ����
	sort(houses.begin(), houses.end());

	// �̺�Ž��
	int left = 1;
	int right = houses.back() - houses.front();
	int answer = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt =  count_routers(houses, mid);

		/*
			�ּҰ����� mid�϶� ��ġ������ C�̻��̸�, 
			������ �� �ø� �� �ִ��� Ȯ���Ѵ�
		*/
		if (cnt >= C)
		{
			answer = max(mid, answer);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << answer;

	return 0;
}