//https://www.acmicpc.net/problem/1476
#include <iostream>

using namespace std;

// 최대범위까지 주어진 조건을 지키는 수 검사
int ESM(int e, int s, int m)
{
	int MAX = 15 * 28 * 19;
	for (int i = 0; i < MAX; i++)
	{
		if (i % 15 == e && i % 28 == s && i % 19 == m)
		{
			return i;
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int E, S, M;
	cin >> E >> S >> M;
	
	// 수의 범위가 1 <= x <= N 이므로, 
	// 1씩 빼서 0 <= x - 1 <= N - 1 로 계산
	cout << ESM(E - 1, S - 1, M - 1) + 1;

	return 0;
}