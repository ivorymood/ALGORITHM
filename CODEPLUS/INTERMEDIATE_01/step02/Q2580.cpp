//https://www.acmicpc.net/problem/2580
#include <iostream>

using namespace std;

const int N = 9;
bool vert[N][N + 1];
bool hori[N][N + 1];
bool box[N][N + 1];
int sdoku[N][N];

// ������ ����Ʈ
void print_sdoku()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << sdoku[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool go(int num)
{
	// ������ ĭ���� ��� ä��� ����Ʈ �� ����
	if (num == N * N)
	{
		print_sdoku();
		return true;
	}

	// ��/��/�ڽ� n��°���� ���ϱ�
	int x = num / N;
	int y = num % N;
	int idx = (x / 3) * 3 + (y / 3);

	// ��ĭ�� �ƴϸ� �ٷ� ����ĭ���� go����Լ� ȣ��
	if (sdoku[x][y] != 0)
	{
		return go(num + 1);
	}
	// ��ĭ�̸�
	else
	{
		/*
			1 ~ 9������ ���� �߿���
			��/��/�ڽ� bool�迭���� ���������� false�� ���ڸ� ��ĭ�� �����ϰ�
			�� �迭�� �ش� ���ڿ� true üũ�� �� go ����Լ� ȣ��
		*/
		for (int k = 1; k <= N; ++k)
		{
			if (!(vert[x][k] || hori[y][k] || box[idx][k]))
			{
				sdoku[x][y] = k;
				vert[x][k] = hori[y][k] = box[idx][k] = true;
				
				// �ѹ��̶� ������ĭ�� �����ߴٸ� ����
				if (go(num + 1))
				{
					return true;
				}
				sdoku[x][y] = 0;
				vert[x][k] = hori[y][k] = box[idx][k] = false;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> sdoku[i][j];

			/*
				��ĭ�� �ƴ϶��
				��/��/�ڽ� bool�迭�� true üũ�ϱ�
			*/
			if (sdoku[i][j] != 0)
			{
				int idx = (i / 3) * 3 + (j / 3);
				box[idx][sdoku[i][j]] = true;
				vert[i][sdoku[i][j]] = true;
				hori[j][sdoku[i][j]] = true;
			}
		}
	}

	// �ϼ� ������ ���� �� ����ϱ�
	go(0);

	return 0;
}