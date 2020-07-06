//https://www.acmicpc.net/problem/10989
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<int> v(10000 + 1);
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		++v[num];
	}

	// [1, 10000] ������ ���� �Էµ� Ƚ����ŭ ���
	for (int i = 1; i <= 10000; ++i)
	{
		if (v[i] > 0)
		{
			for (int j = 0; j < v[i]; ++j)
			{
				cout << i << '\n';
			}
		}
	}

	return 0;
}