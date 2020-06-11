//https://www.acmicpc.net/problem/1062
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count(vector<int>& words, int mask)
{
	int cnt = 0;
	for (int word : words)
	{
		// word에 mask에 포함되지 않는 비트가 없다면 카운팅
		if ((word & ((1 << 26) - 1 - mask)) == 0)
		{
			++cnt;
		}
	}
	return cnt;
}

int go(vector<int> &words, int left, int mask, int strt)
{
	// 글자를 모두 정하면 : 고른 알파벳으로 읽을 수 있는 단어 개수 반환
	if (left == 0)
	{
		return count(words, mask);
	}

	int max_cnt = 0;
	for (int i = strt; i < 26; ++i)
	{
		// 알파벳 acint 는 다시 고르지 않음
		if ((i == 'a' - 'a' || i == 'c' - 'a' || i == 'i' - 'a'
			|| i == 'n' - 'a' || i == 't' - 'a'))
		{
			continue;
		}

		// i번째 알파벳을 선택하는 경우 최대값
		max_cnt = max(go(words, left - 1, mask | (1 << i), i + 1), max_cnt);
	}

	return max_cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N, K;
	cin >> N >> K;
	vector<int> words(N);
	for (int i = 0; i < N; ++i)
	{
		string word;
		cin >> word;

		for (char c : word)
		{
			words[i] |= (1 << (c - 'a'));
		}
	}

	// 모든 단어가 anta ~ tica로 이루어져 있으므로, 
	// 기본마스크에 acint 포함
	int acint_bits = (1 << 'a' - 'a') | (1 << 'c' - 'a') 
					| (1 << 'i' - 'a') | (1 << 'n' - 'a') 
					| (1 << 't' - 'a');

	// K - 5개의 글자를 골라 읽을 수 있는 최대 단어 개수 출력
	cout << go(words, K - 5, acint_bits, 0);

	return 0;
}