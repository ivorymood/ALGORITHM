//https://www.acmicpc.net/problem/11650
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	int x, y;

	// < ������ �����ε� : x ��������, y ��������
	bool operator <(const point& p) const 
	{
		if (x != p.x)
		{
			return x < p.x;
		}
		return y < p.y;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<point> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i].x >> v[i].y;
	}

	// ������ �����ε��� point���͸� ����
	sort(v.begin(), v.end());

	// ���
	for (int i = 0; i < N; ++i)
	{
		cout << v[i].x << ' ' << v[i].y << '\n';
	}

	return 0;
}