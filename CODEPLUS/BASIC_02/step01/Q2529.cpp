//https://www.acmicpc.net/problem/2529
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10;
bool check[MAX];
char max_num[MAX + 1] = {-1, };
char min_num[MAX + 1] = {-1, };

// �� ������ ũ�⸦ c�� �������� �Ǵ��Ͽ� bool ��ȯ
bool comp(int num1, int num2, char c)
{
	if (c == '<')
	{
		return num1 < num2;
	}
	else if (c == '>')
	{
		return num1 > num2;
	}
	return false;
}

// ù��° ���ڹ迭�� ��Ÿ���� ���� �� ũ�� true ��ȯ
bool first_is_bigger(char first[], char second[], int N)
{
	for (int i = 0; i < N; ++i)
	{
		if (first[i] > second[i])
		{
			return true;
		}
		else if (first[i] < second[i])
		{
			return false;
		}
	}
	return false;
}

// �迭�� �� ����
void copy_array(char to[], char from[], int N)
{
	for (int i = 0; i < N; ++i)
	{
		to[i] = from[i];
	}
}

void go(char inequal[], char numbers[], int N, int depth)
{
	// N���� ���� ������ �ϼ��ϸ�
	if (depth == N)
	{
		// max �Ǵ��� ó���̰ų�, max < numbers �϶�
		if (max_num[0] == -1 || first_is_bigger(numbers, max_num, N))
		{
			copy_array(max_num, numbers, N);
		}
		// min �Ǵ��� ó���̰ų�, min > numbers �϶�
		if (min_num[0] == -1 || first_is_bigger(min_num, numbers, N))
		{
			copy_array(min_num, numbers, N);
		}
		return;
	}

	// 0 ~ 9 �� ���� �߿��� ���ǿ� ��ġ�ϴ� ���ڸ� ����
	for (int i = 0; i < 10; ++i)
	{
		if (!check[i])
		{
			// ù��° �����̰ų�, ���� ���ڿ� ���� ���ڰ� ���ǿ� ��ġ�ϸ� ����
			if (depth == 0 || comp(numbers[depth - 1] - '0', i, inequal[depth - 1]))
			{
				check[i] = true;
				numbers[depth] = i + '0';
				go(inequal, numbers, N, depth + 1);
				check[i] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// �Է�
	int k;
	cin >> k;
	char inequal[MAX];
	for (int i = 0; i < k; ++i)
	{
		cin >> inequal[i];
	}

	// dfs�� ������ ���� ���� 
	char numbers[MAX] = {0,};
	go(inequal, numbers, k + 1, 0);

	// ���
	cout << max_num << '\n';
	cout << min_num << '\n';

	return 0;
}