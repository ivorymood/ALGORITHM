//https://www.acmicpc.net/problem/12970
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	
	// A 개수 : a, B 개수 : b
	for (int a = 1; a < N; ++a)
	{
		/*
			1. a + b = N
			2. a * b >= K
			일때, 문제에서 주어진 조건을 만족하는 문자열을 만들 수 있다.
		*/
		int b = N - a;
		if (a * b < K)
		{
			continue;
		}

		/*
			B를 b개만큼 먼저 배치한다음,
			각 A에 대해서 어디에 위치할 것인지 선택한다 
			(몇번째 B앞에 위치할 것인지)

			만약 A가 모든 B뒤에 위치한다면 (i,j)쌍 개수는 새로 증가하지 않는다.
		*/
		vector<int> pos_A(b + 1);
		for (int i = 0; i < a; ++i)
		{
			int after = min(b, K);
			
			++pos_A[b - after];
			K -= after;
		}

		/*
			각 B앞에 위치하기로 결정된 A개수만큼 모두 출력하고 나서
			각자리 B를 출력한다.
		*/
		for (int i = 0; i <= b; ++i)
		{
			for (int j = 0; j < pos_A[i]; ++j)
			{
				cout << 'A';
			}
			if (i < b)
			{
				cout << 'B';
			}
		}
		return 0;
	}

	// 문자열 구성이 불가능한 경우
	cout << -1;

	return 0;
}                          