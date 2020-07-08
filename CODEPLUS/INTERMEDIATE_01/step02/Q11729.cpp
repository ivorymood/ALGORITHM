//https://www.acmicpc.net/problem/11729
#include <iostream>
#include <vector>

using namespace std;

void move_tower(int N, int from, int to, int mid)
{
	if (N == 0)
	{
		return;
	}

	// 1 ~ N -1 탑 이동 : from -> mid (to 경유)
	move_tower(N - 1, from, mid, to);

	// 마지막 원판 : from -> to 이동
	cout << from << ' ' << to << '\n';

	// 1 ~ N -1 탑 이동 : mid -> to (from 경유)
	move_tower(N - 1, mid, to, from);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;

	// 원판 총 이동 횟수 출력
	cout << (1 << N) - 1 << '\n';

	// 하노이탑 이동 : 1번 -> 3번 (2번 경유)
	move_tower(N, 1, 3, 2);
	
	return 0;
}