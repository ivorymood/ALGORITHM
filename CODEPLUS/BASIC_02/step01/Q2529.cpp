//https://www.acmicpc.net/problem/2529
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10;
bool check[MAX];
char max_num[MAX + 1] = {-1, };
char min_num[MAX + 1] = {-1, };

// 두 숫자의 크기를 c를 기준으로 판단하여 bool 반환
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

// 첫번째 문자배열이 나타내는 수가 더 크면 true 반환
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

// 배열의 값 복사
void copy_array(char to[], char from[], int N)
{
	for (int i = 0; i < N; ++i)
	{
		to[i] = from[i];
	}
}

void go(char inequal[], char numbers[], int N, int depth)
{
	// N개의 숫자 조합을 완성하면
	if (depth == N)
	{
		// max 판단이 처음이거나, max < numbers 일때
		if (max_num[0] == -1 || first_is_bigger(numbers, max_num, N))
		{
			copy_array(max_num, numbers, N);
		}
		// min 판단이 처음이거나, min > numbers 일때
		if (min_num[0] == -1 || first_is_bigger(min_num, numbers, N))
		{
			copy_array(min_num, numbers, N);
		}
		return;
	}

	// 0 ~ 9 의 숫자 중에서 조건에 일치하는 숫자를 조합
	for (int i = 0; i < 10; ++i)
	{
		if (!check[i])
		{
			// 첫번째 선택이거나, 이전 숫자와 현재 숫자가 조건에 일치하면 선택
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

	// 입력
	int k;
	cin >> k;
	char inequal[MAX];
	for (int i = 0; i < k; ++i)
	{
		cin >> inequal[i];
	}

	// dfs로 가능한 숫자 조합 
	char numbers[MAX] = {0,};
	go(inequal, numbers, k + 1, 0);

	// 출력
	cout << max_num << '\n';
	cout << min_num << '\n';

	return 0;
}