//https://www.acmicpc.net/problem/15651
#include <iostream>

using namespace std;

const int MAX = 7;
char output[MAX * 2 + 1];

void perm(int N, int M, int depth)
{
	if (depth == M)
	{
		cout << output << '\n';
		return;
	}

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

	int N, M;
	cin >> N >> M;

	perm(N, M, 0);

	return 0;
}