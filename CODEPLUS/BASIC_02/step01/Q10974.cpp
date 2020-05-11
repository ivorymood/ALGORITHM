//https://www.acmicpc.net/problem/10974
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 8;
	
	// 입력
	int N;
	cin >> N;
	int A[MAX] = {0,};
	for (int i = 0; i < N; ++i)
	{
		A[i] = i + 1;
	}
	
	// 사전식 순열 출력
	do {
		for (int i = 0; i < N; ++i)
		{
			cout << A[i] << ' ';
		}
		cout << '\n';
	
	} while (next_permutation(A, A + N));

	return 0;
}