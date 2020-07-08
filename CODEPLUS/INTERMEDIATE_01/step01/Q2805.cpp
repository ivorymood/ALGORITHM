//https://www.acmicpc.net/problem/2805
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// limit������ �ڸ��� ���� ���� �� ���ϱ�
long long get_cut_off_sum(vector<int> &trees, long long limit)
{
	long long left = 0;
	for (int tree : trees)
	{
		if (tree - limit > 0)
		{
			left += tree - limit;
		}
	}
	return left;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	// �Է�
	int N, M;
	cin >> N >> M;
	vector<int> trees(N);
	int max_tree = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> trees[i];
		if (max_tree < trees[i])
		{
			max_tree = trees[i];
		}
	}

	// �̺�Ž��
	long long answer = 0;
	long long left = 0;
	long long right = max_tree;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long sum = get_cut_off_sum(trees, mid);

		// �ڸ� ���� M���� ũ�ų� ���ٸ� �� ���� �ڸ� �� �ִ��� Ȯ���Ѵ�
		if (sum >= M)
		{
			// �ڸ� �� �ִ� �ִ� ���� ����
			answer = max(mid, answer);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	// ���
	cout << answer;

	return 0;
}