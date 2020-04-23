//https://www.acmicpc.net/problem/11722
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
	 D[i] = max(D[k]) + 1 (��, 0 <= k < i, a[k] > a[i])
	*/
	vector<int> len(n, 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (input[j] > input[i] && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
			}
		}
	}

	// D[i] �ִ밪 ���
	cout << *max_element(len.begin(), len.end());

	return 0;
}