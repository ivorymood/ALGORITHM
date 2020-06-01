//https://www.acmicpc.net/problem/2529
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string numbers = "9876543210";

// 두 문자의 크기를 c를 기준으로 판단하여 bool 반환
bool inline check(char ineuql, char A, char B)
{
	return (ineuql == '<') ? (A < B) : (A > B);
}

bool perm(vector<char> &inequal, vector<bool> &visit, string answer, int N, int cnt)
{
	// N개의 자리를 모두 완성하면 출력 후 종료
	if (cnt == N)
	{
		cout << answer << '\n';
		return true;
	}

	// numbers 문자열을 N번째 자리까지 탐색
	for (int i = 0; i < N; ++i)
	{
		if (!visit[i])
		{
			// 첫번째 자리이거나, 조건에 부합하면
			if (cnt == 0 || check(inequal[cnt - 1], answer[cnt - 1], numbers[i]))
			{
				visit[i] = true;
				/*
					한번이라도 성공하면 종료
					오름차순/내림차순 문자열을 dfs탐색하기 때문에, 
					가장 처음에 얻은 결과가 가장 작은/큰 값임.
				*/
				if (perm(inequal, visit, answer + numbers[i], N, cnt + 1))
				{
					return true;
				}
				visit[i] = false;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int K;
	cin >> K;
	vector<char> inequal(K);
	for (int i = 0; i < K; ++i)
	{
		cin >> inequal[i];
	}

	vector<bool> visit(K + 1);
	
	// 내림차순 정렬된 numbers 문자열을 문제조건대로 K + 1개만큼 조합하기.
	perm(inequal, visit, "", K + 1, 0);
	

	// visit벡터를 false로 채우기
	fill(visit.begin(), visit.end(), 0);
	// 오름차순 정렬
	sort(numbers.begin(), numbers.end());
	

	// 오름차순 정렬된 numbers 문자열을 문제조건대로 K + 1개만큼 조합하기. 
	perm(inequal, visit, "", K + 1, 0);
	
	return 0;
}