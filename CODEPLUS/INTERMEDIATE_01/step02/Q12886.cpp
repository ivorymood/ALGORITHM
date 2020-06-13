//https://www.acmicpc.net/problem/12886
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 500;
bool visit[MAX * 2 + 1][MAX * 2 + 1];

int bfs(int A, int B, int C)
{
	// ���� 3�� ����� �ƴϸ� ���� ���� ������ ���� �� ����.
	int sum = A + B + C;
	if (sum % 3)
	{
		return 0;
	}

	/*
		3�� ���� ���� �׻� �����ϹǷ�,
		�� ���� ���� �ȴٸ� ������ �ϳ��� ���� �� �ִ�.
		���� ť���� 2���� ���� push�ϸ� �ȴ�.

		-->ť�� A, B push ��, visit üũ
	*/
	queue<pair<int, int>> q;
	q.push({ A, B });
	visit[A][B] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int z = sum - x - y;
		q.pop();

		// 3 ���� ������ ������ 1 ����
		if (x == y && y == z)
		{
			return 1;
		}

		// xy, yz, zx �̷��� 2���� ¦���� �����̱� 
		int v1[] = { x, y, z };
		int v2[] = { y, z, x };
		for (int i = 0; i < 3; ++i)
		{
			int X = v1[i];
			int Y = v2[i];

			// �� ���� ������ �� �̵�X
			if (X == Y)
			{
				continue;
			}
			/*
				ū�� -= ������
				������ *= 2
			*/
			else if (X > Y)
			{
				X -= Y;
				Y *= 2;
			}
			else if (Y > X)
			{
				Y -= X;
				X *= 2;
			}

			/*
				�̵� �� 3�� ������ min, max ���� ������, �湮 üũ �ϱ�.
				--> ������ �� �ϳ��� �ڵ����� �����ǹǷ�, 3������ �湮üũ�� �Ͱ� ����.
			*/
			int Z = sum - X - Y;
			int MIN = min(min(X, Y), Z);
			int MAX = max(max(X, Y), Z);

			if (!visit[MIN][MAX])
			{
				visit[MIN][MAX] = true;
				q.push({ MIN, MAX });
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	// ���� ���� ������ ���� �� ������ 1, �ƴϸ� 0 ���
	cout << bfs(A, B, C);

	return 0;
}