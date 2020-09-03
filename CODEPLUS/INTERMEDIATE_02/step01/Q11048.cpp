//https://www.acmicpc.net/problem/11048
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
	cin >> N >> M;
	vector<vector<int>> max_candy(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			
			/*
				(i , j) ��ġ������ �ִ� ĵ�� ����
				: ���� ��ġ ĵ�� ���� + [���� ��ġ�� �̵� ������ ���� ��ġ������ �ִ� ĵ�� ����]
			*/
			cin >> max_candy[i][j];
			max_candy[i][j] += max({ max_candy[i - 1][j], max_candy[i][j - 1], max_candy[i - 1][j - 1] });
		}
	}

	// ���
	cout << max_candy[N][M];

	return 0;
}