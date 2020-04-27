//https://www.acmicpc.net/problem/17404
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	const int MAX = 1000;
	int rgb[MAX + 1][3];
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}
	
	/*
	점화식
		D[i] : i 번째 집까지 색칠한 최소 비용.
		D[i] = i 번째 집 색칠 비용 + (i - 1)번째 집까지 색칠한 최소 비용

		i번째 집은 (i - 1)번째 집과 색이 같으면 안되므로
		--> D[i][k] = rgb[i][k] + min(D[i - 1][(k + 1) % 3, D[i - 1][(k + 2) % d]]) (0 <= k <= 2)
	

		추가조건) 1번째 집은 N번째 집과 색이 같으면 안된다.
		1번째 집이 R일때, G일때, B일때를 각각 구해서 최소비용 구하기
		
		* 주의사항 *
		a. 1번째 집의 색깔이 X일때, D[1]과 D[2]는 이미 정해져 있다
		b. 1번째 집의 색깔이 X일때, N번째 집의 색깔은 X이면 안된다.
	*/
	int min_cost = MAX * MAX;
	for (int k = 0; k < 3; k++)
	{
		int cost[MAX + 1][3] = { 0, };

		// 주의사항 a 처리
		for (int i = 0; i < 3; i++)
		{
			if (i == k)
			{
				cost[1][i] = rgb[1][i];
				continue;
			}
			cost[1][i] = 1000;
		}

		// 점화식 구현
		for (int i = 2; i <= N; i++)
		{
			cost[i][0] = rgb[i][0] + min(cost[i - 1][1], cost[i - 1][2]);
			cost[i][1] = rgb[i][1] + min(cost[i - 1][0], cost[i - 1][2]);
			cost[i][2] = rgb[i][2] + min(cost[i - 1][0], cost[i - 1][1]);
		}

		// 주의사항 b처리
		for (int i = 0; i < 3; i++)
		{
			if (i == k)
			{
				continue;
			}
			min_cost = min(min_cost, cost[N][i]);
		}
	}

	cout << min_cost;

	return 0;
}