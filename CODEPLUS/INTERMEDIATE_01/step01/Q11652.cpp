//https://www.acmicpc.net/problem/11652
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
	int N;
	cin >> N;
	vector<long long> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	// �������� ����
	sort(v.begin(), v.end());


	int max_cnt = 1;
	int last_cnt = 1;
	long long num = v[0];

	// ���� ���ڿ� ���Ͽ� ���� ���ڵ� ���� ī����
	for (int i = 1; i < N; ++i)
	{
		if (v[i - 1] == v[i])
		{
			++last_cnt;
		}
		else
		{
			last_cnt = 1;
		}

		// max_cnt���� ������ ������ num����
		if (max_cnt < last_cnt)
		{
			max_cnt = last_cnt;
			num = v[i];
		}
	}

	cout << num;

	return 0;
}