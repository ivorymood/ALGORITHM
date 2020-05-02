//https://www.acmicpc.net/problem/1107
#include <iostream>
#include <algorithm>

using namespace std;

int possible(int N, bool is_broken[])
{
	int len = 0;
	do
	{
		if (is_broken[N % 10])
		{
			return 0;
		}
		len++;
		N /= 10;
	} while (N);

	return len;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int NOW = 100;
	const int MAX = 1'000'000;

	// �Է�
	int N, M;
	cin >> N >> M;
	bool is_broken[10] = { 0, };
	
	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		is_broken[tmp] = true;
	}

	// ���� ä�ο��� +/- ��ư������ �̵��ϴ� Ƚ��
	int cnt = abs(N - NOW);

	for (int i = 0; i <= MAX; i++)
	{
		// i�� �̷�� ���� �� ���峭 ��ư�� ������, ���ڱ��� ��ȯ
		int len = possible(i, is_broken);
		if (len)
		{
			// ��ư ������ Ƚ���� �� ������
			if (cnt > abs(N - i) + len)
			{
				cnt = abs(N - i) + len;
			}
		}
	}

	cout << cnt;

	return 0;
}