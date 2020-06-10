//https://www.acmicpc.net/problem/16198
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_sum;

void go(vector<int>& nrg, int sum)
{
	// ������ 2���� ������ �ִ��հ� ���� �� ����
	int N = nrg.size();
	if (N == 2)
	{
		max_sum = max(sum, max_sum);
		return;
	}

	// new_nrg�� i��°�� ������ ������ ���� �� �ֱ�
	vector<int> new_nrg(N - 1);
	for (int i = 1; i < N - 1; ++i)
	{
		int idx = 0;
		for (int j = 0; j < N; ++j)
		{
			if (j == i)
			{
				continue;
			}
			new_nrg[idx++] = nrg[j];
		}

		// ���ο� �������Ϳ� sum + nrg[i - 1] * nrg[i + 1]������ ����Լ� ȣ��
		go(new_nrg, sum + nrg[i - 1] * nrg[i + 1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<int> nrg(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nrg[i];
	}

	/*
		������ 2�� ���������� x��° ������ ����鼭 
		x - 1��° * x + 1��° ���� �հ踦 ���ϴ� ����Լ�
	*/
	go(nrg, 0);

	// ���
	cout << max_sum;

	return 0;
}