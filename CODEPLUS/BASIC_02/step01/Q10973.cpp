//https://www.acmicpc.net/problem/10973
#include <iostream>

using namespace std;

bool prev_permutation(int A[], int N)
{

	// i : 뒤에서부터 시작 되는 가장 긴 증가 수열의 마지막 인덱스
	int i = N - 1;
	while (i > 0 && A[i - 1] < A[i])
	{
		--i;
	}

	// 전체가 오름차순인 상태 : 첫번째 순열
	if (i <= 0)
	{
		return false;
	}

	// j : i - 1 < j , A[i - 1] > A[j] 인 수. 
	// i - 1번째 수보다 작은 수 찾기 
	int j = N - 1;
	while (A[i - 1] < A[j])
	{
		--j;
	}

	// i번째 수와 j번째 수를 바꾸기
	swap(A[i - 1], A[j]);

	// i 번째 수부터 마지막까지 모두 뒤집기
	for (int k = i, h = N - 1; k < h; ++k, --h)
	{
		swap(A[k], A[h]);
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 10'000;

	int N;
	cin >> N;
	int A[MAX] = {0,};
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	
	// 이전 순열이 존재하면 출력
	if (prev_permutation(A, N))
	{
		for (int i = 0; i < N; ++i)
		{
			cout << A[i] << ' ';
		}
	}
	// 존재하지 않으면 -1 출력
	else
	{
		cout << -1;
	}

	return 0;
}