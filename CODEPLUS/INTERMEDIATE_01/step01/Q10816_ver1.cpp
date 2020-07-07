//https://www.acmicpc.net/problem/10816
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// target�� ������ ���� ������ ��� �� ���� ù��° �ε��� ���ϱ�
int lower_bound(vector<int> &cards, int left, int right, int target)
{
	int min_idx = -1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		
		if (cards[mid] == target)
		{
			min_idx = mid;
			right = mid - 1;
		}
		else if (cards[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return min_idx;
}

// target�� ������ ���� ������ ��� �� ���� ������ �ε��� ���ϱ�
int upper_bound(vector<int>& cards, int left, int right, int target)
{
	int max_idx = -1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (cards[mid] == target)
		{
			max_idx = mid;
			left = mid + 1;
		}
		else if (cards[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return max_idx;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, M;
	cin >> N;
	vector<int> cards(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> cards[i];
	}

	// �̺�Ž���� ���� ������ ����
	sort(cards.begin(), cards.end());

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int test;
		cin >> test;

		// test�� ������ ����� ���� ù��° �ε����� ���� ������ �ε���
		int min_idx = lower_bound(cards, 0, N - 1, test);
		int max_idx = upper_bound(cards, 0, N - 1, test);

		// cards�� test���� ���ԵǾ� ���� �ʴٸ� 0, ���ԵǾ� ������ ���� ���
		cout << ((min_idx < 0) ? 0 : max_idx - (min_idx - 1)) << ' ';
	}

	return 0;
}