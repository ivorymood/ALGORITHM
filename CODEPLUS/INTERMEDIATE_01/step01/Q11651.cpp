//https://www.acmicpc.net/problem/11651
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2��° ��� ��������, 1��° ��� ������������ ����
bool compare(pair<int, int> &A, pair<int, int> &B)
{
	if (A.second != B.second)
	{
		return A.second < B.second;
	}
	return A.first < B.first;
}

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

	// compare �������� ����
	sort(v.begin(), v.end(), compare);

	// ���
	for (int i = 0; i < N; ++i)
	{
		cout << v[i].first << ' ' << v[i].second << '\n';
	}

	return 0;
}