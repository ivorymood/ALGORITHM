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

	// �Է�
	int N;
	cin >> N;
	vector<string> words(N);
	
	// ���ĺ��� ó������ �Էµ� ������ ������ ����
	// ���ĺ��� ���� �ڸ���
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

	// cnt : ���ĺ� �Է� ����
	// ���ĺ� �Է� ������ cnt���� ���ڸ� 10 - cnt���� 9���� �ű��
	vector<int> numbers(cnt);
	for (int i = 0; i < cnt; ++i)
	{
		numbers[i] = 10 - cnt + i;
	}

	// ������ ���� ū �հ踦 ���Ѵ�
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