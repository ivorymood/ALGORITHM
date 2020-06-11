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
		// word�� mask�� ���Ե��� �ʴ� ��Ʈ�� ���ٸ� ī����
		if ((word & ((1 << 26) - 1 - mask)) == 0)
		{
			++cnt;
		}
	}
	return cnt;
}

int go(vector<int> &words, int left, int mask, int strt)
{
	// ���ڸ� ��� ���ϸ� : �� ���ĺ����� ���� �� �ִ� �ܾ� ���� ��ȯ
	if (left == 0)
	{
		return count(words, mask);
	}

	int max_cnt = 0;
	for (int i = strt; i < 26; ++i)
	{
		// ���ĺ� acint �� �ٽ� ���� ����
		if ((i == 'a' - 'a' || i == 'c' - 'a' || i == 'i' - 'a'
			|| i == 'n' - 'a' || i == 't' - 'a'))
		{
			continue;
		}

		// i��° ���ĺ��� �����ϴ� ��� �ִ밪
		max_cnt = max(go(words, left - 1, mask | (1 << i), i + 1), max_cnt);
	}

	return max_cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
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

	// ��� �ܾ anta ~ tica�� �̷���� �����Ƿ�, 
	// �⺻����ũ�� acint ����
	int acint_bits = (1 << 'a' - 'a') | (1 << 'c' - 'a') 
					| (1 << 'i' - 'a') | (1 << 'n' - 'a') 
					| (1 << 't' - 'a');

	// K - 5���� ���ڸ� ��� ���� �� �ִ� �ִ� �ܾ� ���� ���
	cout << go(words, K - 5, acint_bits, 0);

	return 0;
}