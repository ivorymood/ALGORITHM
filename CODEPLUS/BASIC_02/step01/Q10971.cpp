//https://www.acmicpc.net/problem/10971
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 10;
	int min_cost = 100'000'000;

	// 입력
	int N;
	cin >> N;
	int W[MAX][MAX];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> W[i][j];
		}
	}

	// city 인덱스 배열
	// 첫번째 도시로 다시 돌아오기 위해서 크기를 MAX + 1로 선언
	int city[MAX + 1] = { 0, };
	for (int i = 0; i < N; ++i)
	{
		city[i] = i;
	}

	// 순회가 가능한 경우, 최소 순회비용 구하기 - 완전탐색
	do {
	
		bool possible = true;
		int cost = 0;
		
		// 가장 마지막으로 갈 도시 = 첫번째 도시
		city[N] = city[0];
		for (int i = 0; i < N; ++i)
		{
			// 갈 수 없는 경우면 break
			if (W[city[i]][city[i + 1]] == 0)
			{
				possible = false;
				break;
			}

			cost += W[city[i]][city[i + 1]];
		}

		// 가능한 순회면 최소값 구하기
		if (possible && min_cost > cost)
		{
			min_cost = cost;
		}
	
		/*
			순회가 환형이므로, 시작점은 1로 고정해도 된다. 
			ex) A B C D == B C D A == C D A B == D A B C
		*/
	} while (next_permutation(city + 1, city + N));

	cout << min_cost;

	return 0;
}