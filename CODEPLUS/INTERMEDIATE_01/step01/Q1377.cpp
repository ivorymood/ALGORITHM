//https://www.acmicpc.net/problem/1377
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
		// �Էµ� ���� ����
		v[i].second = i;
		cin >> v[i].first;
	}

	// ����
	sort(v.begin(), v.end());

	// �Էµ� ������ ���ĵ� ���� ��
	int max_moved = 0;
	for (int i = 0; i < N; ++i)
	{
		// �ڿ��� ������ �̵��� �ִ� ĭ�� ���ϱ�
		if (max_moved < v[i].second - i)
		{
			max_moved = v[i].second - i;
		}
	}

	// �ִ�� �̵��� Ƚ�� + 1 : ��ȸ���� ���������� �Ǿ�����
	cout << max_moved + 1;

	return 0;
}