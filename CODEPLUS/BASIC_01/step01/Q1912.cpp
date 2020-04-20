//https://www.acmicpc.net/problem/1912
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	/*
		점화식 : D[i] = i번째 수로 끝나는 가장 큰 연속합
		
		--> D[i - 1] >= 0 이라면 연속합 계산.
		--> D[i - 1] <  0 이면 A[i]로 새로운 연속합 시작.
	*/
	vector<int> S(n);
	S[0] = A[0];
	for (int i = 1; i < n; i++)
	{
		if (S[i - 1] >= 0)
		{
			S[i] = S[i - 1] + A[i];
		}
		else
		{
			S[i] = A[i];
		}
	}

	cout << *max_element(S.begin(), S.end());

	return 0;
}