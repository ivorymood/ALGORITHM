//https://www.acmicpc.net/problem/2875
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	// ���л� + ���л��� ���� �ٸ��� �� ���� ���°� ������ �����ؾ� �Ѵ�
	int team = 0;
	while (N - 2 >= 0 && M - 1 >= 0 && N + M - 3 >= K)
	{
		N -= 2;
		M -= 1;
		++team;
	}

	cout << team;

	return 0;
}