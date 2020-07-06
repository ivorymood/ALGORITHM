//https://www.acmicpc.net/problem/11650
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
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}

	// �������� ����
	sort(v.begin(), v.end());

	// ���
	for (int i = 0; i < N; ++i)
	{
		cout << v[i].first << ' ' <<  v[i].second << '\n';
	}

	return 0;
}