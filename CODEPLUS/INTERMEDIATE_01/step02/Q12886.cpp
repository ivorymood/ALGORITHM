//https://www.acmicpc.net/problem/12886
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 500;
bool visit[MAX * 2 + 1][MAX * 2 + 1];

int bfs(int A, int B, int C)
{
	// 합이 3의 배수가 아니면 돌을 같은 개수로 나눌 수 없다.
	int sum = A + B + C;
	if (sum % 3)
	{
		return 0;
	}

	/*
		3개 수의 합은 항상 일정하므로,
		두 수의 값을 안다면 나머지 하나를 구할 수 있다.
		따라서 큐에는 2개의 수만 push하면 된다.

		-->큐에 A, B push 후, visit 체크
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

		// 3 수의 개수가 같으면 1 리턴
		if (x == y && y == z)
		{
			return 1;
		}

		// xy, yz, zx 이렇게 2개씩 짝지어 움직이기 
		int v1[] = { x, y, z };
		int v2[] = { y, z, x };
		for (int i = 0; i < 3; ++i)
		{
			int X = v1[i];
			int Y = v2[i];

			// 두 수가 같으면 돌 이동X
			if (X == Y)
			{
				continue;
			}
			/*
				큰수 -= 작은수
				작은수 *= 2
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
				이동 후 3개 수에서 min, max 값을 구한후, 방문 체크 하기.
				--> 나머지 값 하나는 자동으로 결정되므로, 3개수를 방문체크한 것과 같다.
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

	// 돌을 같은 개수로 만들 수 있으면 1, 아니면 0 출력
	cout << bfs(A, B, C);

	return 0;
}