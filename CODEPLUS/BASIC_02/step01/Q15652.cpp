//https://www.acmicpc.net/problem/15652
#include <iostream>

using namespace std;

const int MAX = 8;
char output[MAX * 2 + 1];

void perm(int N, int M, int depth, int start)
{
	// depth가 M에 도달하면 출력
	if (depth == M)
	{
		cout << output << '\n';
		return;
	}

	// 중복 허용, 비내림차순(다음 숫자가 현재 숫자보다 같거나 큰 순서)인 수열 입력
	for (int i = start; i <= N; i++)
	{
		output[depth * 2] = i + '0';
		output[depth * 2 + 1] = ' ';
		perm(N, M, depth + 1, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N, M;
	cin >> N >> M;

	// 수열 출력
	perm(N, M, 0, 1);

	return 0;
}