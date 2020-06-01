//https://www.acmicpc.net/problem/1339
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<string> words(N);
	
	// 알파벳이 처음으로 입력된 순서를 저장할 벡터
	// 알파벳의 정렬 자릿값
	vector<int> alpha(26, -1);
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> words[i];
		for (char c : words[i])
		{
			if (alpha[c - 'A'] < 0)
			{
				alpha[c - 'A'] = cnt++;
			}
		}
	}

	// cnt : 알파벳 입력 갯수
	// 알파벳 입력 순으로 cnt개의 숫자를 10 - cnt부터 9까지 매긴다
	vector<int> numbers(cnt);
	for (int i = 0; i < cnt; ++i)
	{
		numbers[i] = 10 - cnt + i;
	}

	// 순열로 가장 큰 합계를 구한다
	int max_sum = 0;
	do {
		int sum = 0;
		for (string wd : words)
		{
			int num = 0;
			for (char c : wd)
			{
				num *= 10;
				num += numbers[alpha[c - 'A']];
			}
			sum += num;
		}

		max_sum = max(max_sum, sum);

	} while (next_permutation(numbers.begin(), numbers.end()));

	cout << max_sum;

	return 0;
}