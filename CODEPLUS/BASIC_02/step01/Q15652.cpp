//https://www.acmicpc.net/problem/15652
#include <iostream>

using namespace std;

const int MAX = 8;
char output[MAX * 2 + 1];

void perm(int N, int M, int depth, int start)
{
	if (depth == M)
	{
		cout << output << '\n';
		return;
	}

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

	int N, M;
	cin >> N >> M;

	perm(N, M, 0, 1);

	return 0;
}