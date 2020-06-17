//https://www.acmicpc.net/problem/11047
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, K;
	cin >> N >> K;
	vector<int> coins(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> coins[i];
	}

	// K���� ���� �ִ� �׼��� ������ ���� ���� �ᳪ����.  
	int cnt = 0;
	for (int i = N - 1; i >= 0; --i)
	{
		// cnt += i��° ������ �ִ�� ���� �ִ� ����
		cnt += K / coins[i];
		
		// K -= i��° ������ �ִ�� �� �ݾ�
		K %= coins[i];
	}

	cout << cnt;

	return 0;
}