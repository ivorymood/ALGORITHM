//https://www.acmicpc.net/problem/1248
#include <iostream>
#include <vector>

using namespace std;

// ���ڰ� ��ȣ�� ��ġ�ϴ��� Ȯ��
bool inline sign_check(int num, int sign)
{
	if (sign == 0)
	{
		return num == 0;
	}
	else
	{
		return num * sign > 0;
	}
}

// ���� ���� ���ڰ� ������ ��ȣ ���ǿ� ��ġ�ϴ��� Ȯ��
bool check(vector<vector<int>> &sign, vector<int> &numbers, int target, int depth)
{
	int sum = target;
	for (int i = depth - 1; i >= 0; --i)
	{
		// i ~ depth �ڸ������� ���� ��ȣ ���ǿ� ��ġ�ϴ��� Ȯ��
		sum += numbers[i];
		if (!sign_check(sum, sign[i][depth]))
		{
			return false;
		}
	}
	return true;
}

bool go(vector<vector<int>> &sign, vector<int> &numbers, int N, int depth)
{
	// ���ڰ� ��� ���յǸ� ���
	if (depth == N)
	{
		for (int i = 0; i < N; ++i)
		{
			cout << numbers[i] << ' ';
		}
		cout << '\n';
		return true;
	}

	// ��ȣ�� 0�� ��
	if (sign[depth][depth] == 0)
	{
		numbers[depth] = 0;
		return go(sign, numbers, N, depth + 1);
	}

	// ��ȣ�� 0���� ũ�ų� ������
	for (int i = 1; i <= 10; ++i)
	{
		// ���� ���� ���ڿ� ��ȣ �ݿ�
		int target = i * sign[depth][depth];
		
		// ���� ���� ���ڰ� ������ ��ȣ ���ǿ� ��ġ�ϴ��� Ȯ��
		if (check(sign, numbers, target, depth))
		{
			numbers[depth] = target;

			// �ѹ��̶� ������ �ϼ��Ǿ� ��µǸ� ����
			if (go(sign, numbers, N, depth + 1))
			{
				return true;
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
	int N;
	cin >> N;
	string s;
	cin >> s;

	// -, 0, + ��ȣ�� -1, 0, 1 �� ��ȯ�Ͽ� ���� ����
	vector<vector<int>> sign(N, vector<int>(N));
	int idx = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			if (s[idx] == '0')
			{
				sign[i][j] = 0;
			}
			else if (s[idx] == '+')
			{
				sign[i][j] = 1;
			}
			else 
			{
				sign[i][j] = -1;
			}
			++idx;
		}
	}

	// ��Ʈ��ŷ - ���� ����
	vector<int> numbers(N);
	go(sign, numbers, N, 0);

	return 0;
}