//https://www.acmicpc.net/problem/2133
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ���� ����, �Է�
	int const MAX = 30;
	int const len2 = 3;
	int tiles[MAX + 1] = {0, };

	int n;
	cin >> n;

	/*
	��ȭ��
		D[i] : 3 * i �� 1*2, 2*1�� ä��� ����� ��
		Type 1 : 3*2�� ä��� ���
		Type 2 : �� ���̿� 2���� ����� �� �ִ�

		--> D[i] = D[i - 2] * 3 + D[i - 4] * 2 + D[i - 6] * 2 ...
	*/
	tiles[0] = 1;
	for (int i = 2; i <= n; i += 2)
	{
		tiles[i] = tiles[i - 2] * len2;
		for (int j = i - 4; j >= 0; j -= 2)
		{
			tiles[i] += tiles[j] * 2;
		}
	}

	cout << tiles[n];

	return 0;
}