//https://www.acmicpc.net/problem/11729
#include <iostream>
#include <vector>

using namespace std;

void move_tower(int N, int from, int to, int mid)
{
	if (N == 0)
	{
		return;
	}

	// 1 ~ N -1 ž �̵� : from -> mid (to ����)
	move_tower(N - 1, from, mid, to);

	// ������ ���� : from -> to �̵�
	cout << from << ' ' << to << '\n';

	// 1 ~ N -1 ž �̵� : mid -> to (from ����)
	move_tower(N - 1, mid, to, from);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;

	// ���� �� �̵� Ƚ�� ���
	cout << (1 << N) - 1 << '\n';

	// �ϳ���ž �̵� : 1�� -> 3�� (2�� ����)
	move_tower(N, 1, 3, 2);
	
	return 0;
}