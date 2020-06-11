//https://www.acmicpc.net/problem/1987
#include <iostream>
#include <vector>

using namespace std;

int dr_x[] = { 0, 1, 0, -1 };
int dr_y[] = { 1, 0, -1, 0 };

int go(vector<string>& alpha, vector<bool>& visit, int x, int y)
{
	int max_cnt = 1;

	// 4���� Ž��
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dr_x[i];
		int ny = y + dr_y[i];

		// ���� ���� ����� continue
		if ((nx < 0 || nx >= alpha.size() || ny < 0 || ny >= alpha[0].size()))
		{
			continue;
		}

		// ����ĭ�� ���ĺ��� �湮������ ������
		int idx = alpha[nx][ny] - 'A';
		if (!visit[idx])
		{
			visit[idx] = true;

			// �ѹ� �̵��� ������ �̵�Ƚ�� + 1 
			int cnt = go(alpha, visit, nx, ny) + 1;

			// �ִ밪 ���ϱ�
			if (max_cnt < cnt)
			{
				max_cnt = cnt;
			}

			visit[idx] = false;
		}
	}
	return max_cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int R, C;
	cin >> R >> C;
	vector<string> alpha(R);
	for (int i = 0; i < R; ++i)
	{
		cin >> alpha[i];
	}

	// ���ĺ� �湮 üũ�� bool����
	vector<bool> visit(26);
	// ù��° ��ġ �湮 üũ
	visit[alpha[0][0] - 'A'] = true;

	// �ִ�� �̵��� �� �ִ� ĭ�� ���
	cout << go(alpha, visit, 0, 0);

	return 0;
}
