//https://www.acmicpc.net/problem/1406
#include <iostream>
#include <cstring>

using namespace std;

// main�Լ� ���û����� �ʰ� ����(C6262)�� ���ϱ� ���� ���������� ����
const int MAX = 600001;
char arr_left[MAX];
char arr_right[MAX];

int main()
{
	// ����� ���
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// left�迭�� �ʱ� ���ڿ� �Է�
	cin >> arr_left;
	int idx_left = strlen(arr_left);
	int idx_right = 0;

	int n;
	cin >> n;
	while (n--)
	{
		// �� �迭�� idx�� �������� Ŀ���� ����/������ ����
		char cmd;
		cin >> cmd;

		switch (cmd)
		{
		case 'L':
			if (idx_left <= 0)
			{
				continue;
			}
			arr_right[idx_right++] = arr_left[--idx_left];
			break;

		case 'D':
			if (idx_right <= 0)
			{
				continue;
			}
			arr_left[idx_left++] = arr_right[--idx_right];
			break;

		case 'B':
			if (idx_left <= 0)
			{
				continue;
			}
			idx_left--;
			break;

		case 'P':
			cin >> arr_left[idx_left++];
			break;
		}
	}

	// right�迭 -> left�迭 �ű��
	while (idx_right >= 0)
	{
		arr_left[idx_left++] = arr_right[--idx_right];
	}

	// ���
	cout << arr_left;

	return 0;
}