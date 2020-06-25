//https://www.acmicpc.net/problem/2875
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	// 여학생 + 남학생이 팀을 꾸리고 난 후의 상태가 조건을 충족해야 한다
	int team = 0;
	while (N - 2 >= 0 && M - 1 >= 0 && N + M - 3 >= K)
	{
		N -= 2;
		M -= 1;
		++team;
	}

	cout << team;

	return 0;
}