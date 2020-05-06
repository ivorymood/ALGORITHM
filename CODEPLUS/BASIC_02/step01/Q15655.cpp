//https://www.acmicpc.net/problem/15655
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 8;
int numbers[MAX];
bool visited[MAX];
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
	}

	// 오름차순, 중복 허용X
	for (int i = start; i < N; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			output[depth] = numbers[i];
			dps(N, M, depth + 1, i + 1);
			visited[i] = false;
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}

	// 정렬
	sort(numbers, numbers + N);

	dps(N, M, 0, 0);

	return 0;
}