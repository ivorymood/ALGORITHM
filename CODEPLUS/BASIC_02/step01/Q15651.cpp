//https://www.acmicpc.net/problem/15651
#include <iostream>

using namespace std;

const int MAX = 7;
char output[MAX * 2 + 1];

void perm(int N, int M, int depth)
{
	// depth가 M에 도달하면 출력
	if (depth == M)
	{
		cout << output << '\n';
		return;
	}

	// 중복을 허용하고 정렬 순서가 없는 수열 입력
	for (int i = 1; i <= N; ++i)
	{
		output[depth * 2] = i + '0';
		output[depth * 2 + 1] = ' ';
		perm(N, M, depth + 1);
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
	perm(N, M, 0);

	return 0;
}