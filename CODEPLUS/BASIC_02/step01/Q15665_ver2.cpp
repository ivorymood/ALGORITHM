//https://www.acmicpc.net/problem/15665
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 7;
int numbers[MAX];
int output[MAX];

void dfs(int N, int M, int depth)
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

	// 중복 허용. 정렬X
	for (int i = 0; i < N; ++i)
	{
		output[depth] = numbers[i];
		dfs(N, M, depth + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	int tmp[MAX];
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp[i];
	}

	// 사전순 출력을 위해 오름차순 정렬
	sort(tmp, tmp + N);

	// 중복을 제거하여 숫자열 저장.
	numbers[0] = tmp[0];
	int idx = 1;
	for (int i = 1; i < N; ++i)
	{
		if (tmp[i - 1] != tmp[i])
		{
			numbers[idx] = tmp[i];
			++idx;
		}
	}

	dfs(idx, M, 0);

	return 0;
}