//https://www.acmicpc.net/problem/11650
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	int x, y;

	// < 연산자 오버로딩 : x 오름차순, y 오름차순
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

	// 입력
	int N;
	cin >> N;
	vector<point> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i].x >> v[i].y;
	}

	// 연산자 오버로딩된 point벡터를 정렬
	sort(v.begin(), v.end());

	// 출력
	for (int i = 0; i < N; ++i)
	{
		cout << v[i].x << ' ' << v[i].y << '\n';
	}

	return 0;
}