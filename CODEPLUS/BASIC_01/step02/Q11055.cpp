//https://www.acmicpc.net/problem/11055
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	/*
		��ȭ�� :
		D[i] = max(D[k]) + a[i] (��, 0 <= k < i, a[k] < a[i])
	*/
	vector<int> max_sum(n);
	for (int i = 0; i < n; i++)
	{
		// a[i]�� �κ��������� 1��°�� ��� ó��
		max_sum[i] = input[i];
		for (int j = 0; j < i; j++)
		{
			if (input[j] < input[i] && max_sum[j] + input[i] > max_sum[i])
			{
				max_sum[i] = max_sum[j] + input[i];
			}
		}
	}

	// D[i] �ִ밪 ���
	cout << *max_element(max_sum.begin(), max_sum.end());

	return 0;
}