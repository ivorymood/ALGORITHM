//https://www.acmicpc.net/problem/10816
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, M;
	cin >> N;
	vector<int> cards(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> cards[i];
	}

	// �̺�Ž���� ���� ������ ����
	sort(cards.begin(), cards.end());

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int test;
		cin >> test;

		// test�� ���ų� ū ����� ù��° �ε���
		auto min_it = lower_bound(cards.begin(), cards.end(), test);
		
		// test���� ū ����� ù��° �ε���
		auto max_it = upper_bound(cards.begin(), cards.end(), test);

	
		// cards�� test���� ���ԵǾ� ���� �ʴٸ� 0, ���ԵǾ� ������ ���� ���
		cout << ((max_it - min_it == 0) ? 0 : max_it - min_it) << ' ';
	}

	return 0;
}