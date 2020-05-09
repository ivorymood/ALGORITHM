//https://www.acmicpc.net/problem/15665
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

const int MAX = 7;
int numbers[MAX];
int output[MAX];
unordered_map<int, int> cnt_map;

/*
	만들어진 숫자열 -> 숫자로 전환하여 map에 등록하고 카운팅
	처음 한번만 출력한다. 
*/
void dfs(int N, int M, int depth, int sum)
{
	if (depth == M)
	{
		if (++cnt_map[sum] == 1)
		{
			for (int i = 0; i < M; ++i)
			{
				cout << output[i] << ' ';
			}
			cout << '\n';
		}

		return;
	}

	// 중복 허용. 정렬X
	for (int i = 0; i < N; ++i)
	{
		sum += numbers[i] * pow(10, M - depth - 1);
		output[depth] = numbers[i];
		dfs(N, M, depth + 1, sum);
		sum -= numbers[i] * pow(10, M - depth - 1);
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

	// 사전순 출력을 위해 오름차순 정렬
	sort(numbers, numbers + N);
	
	dfs(N, M, 0, 0);

	return 0;
}