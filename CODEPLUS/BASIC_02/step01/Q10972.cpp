//https://www.acmicpc.net/problem/10972
#include <iostream>

using namespace std;

bool next_permutation(int numbers[], int N)
{
	// i : 뒤에서부터 시작 되는 가장 긴 감소 수열의 마지막 인덱스
	int i = N - 1;
	while (i > 0 && numbers[i - 1] > numbers[i])
	{
		--i;
	}

	// 전체가 내림차순인 상태 : 마지막 순열
	if (i <= 0)
	{
		return false;
	}

	// j : i - 1 < j , A[i - 1] < A[j] 인 수. 
	// i번째 수 바로 앞의 수보다 큰 수 찾기 
	int j = N - 1;
	while (numbers[i - 1] > numbers[j])
	{
		--j;
	}

	// i번째 수와 j번째 수를 바꾸기
	swap(numbers[i - 1], numbers[j]);

	// i 번째 수부터 마지막까지 모두 뒤집기
	for (int k = i, h = N - 1; k < h; ++k, --h)
	{
		swap(numbers[k], numbers[h]);
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 10000;
	int numbers[MAX];

	// 입력
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> numbers[i];
	}

	// 다음 순열이 존재하면 출력
	if (next_permutation(numbers, N))
	{
		for (int i = 0; i < N; ++i)
		{
			cout << numbers[i] << ' ';
		}
		cout << '\n';
	}
	// 존재하지 않으면 -1 출력
	else
	{
		cout << -1;
	}

	return 0;
}