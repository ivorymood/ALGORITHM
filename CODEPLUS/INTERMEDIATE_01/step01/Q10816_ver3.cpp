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

		// test�� ���� ��ҵ��� begin�� end �ݺ��� pair
		auto pair_it = equal_range(cards.begin(), cards.end(), test);

		// cards�� test���� ���ԵǾ� ���� �ʴٸ� 0, ���ԵǾ� ������ ���� ���
		if (pair_it.second - pair_it.first == 0)
		{
			cout << 0 << ' ';
		}
		else
		{
			cout << (pair_it.second - pair_it.first) << ' ';
		}
	}

	return 0;
}