//https://www.acmicpc.net/problem/15663
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

const int MAX = 8;
bool visited[MAX];
int numbers[MAX];
int output[MAX];
unordered_map<int, int> count_map;

/*
	만들어진 숫자열 -> 숫자로 변환하여 map에 등록.
	중복하지 않으면 출력
*/
void dfs(int N, int M, int depth, int sum)
{
	if (depth == M)
	{
		if (++count_map[sum] == 1)
		{
			for (int i = 0; i < M; ++i)
			{
				cout << output[i] << ' ';
			}
			cout << '\n';
		}

		return;
	}
	
	for (int i = 0; i < N; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			sum += numbers[i] * pow(10, depth);
			output[depth] = numbers[i];
			
			dfs(N, M, depth + 1, sum);
			
			sum -= numbers[i] * pow(10, depth);
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
	for (int i = 0; i < N; ++i)
	{
		cin >> numbers[i];
	}

	sort(numbers, numbers + N);

	dfs(N, M, 0, 0);

	return 0;
}