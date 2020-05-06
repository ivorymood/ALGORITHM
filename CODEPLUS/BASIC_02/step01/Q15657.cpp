//https://www.acmicpc.net/problem/15657
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 8;
int numbers[MAX];
int output[MAX];

void dps(int N, int M, int depth, int start)
{
	if (depth == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << output[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 비내림차순, 중복허용
	for (int i = start; i < N; ++i)
	{
		output[depth] = numbers[i];
		dps(N, M, depth + 1, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		cin >> numbers[i];
	}

	// 정렬
	sort(numbers, numbers + N);

	dps(N, M, 0, 0);

	return 0;
}