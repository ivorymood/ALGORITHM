//https://www.acmicpc.net/problem/1248
#include <iostream>
#include <vector>

using namespace std;

// 숫자가 부호와 일치하는지 확인
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

// 새로 들어올 숫자가 구간별 부호 조건에 일치하는지 확인
bool check(vector<vector<int>> &sign, vector<int> &numbers, int target, int depth)
{
	int sum = target;
	for (int i = depth - 1; i >= 0; --i)
	{
		// i ~ depth 자리까지의 합이 부호 조건에 일치하는지 확인
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
	// 숫자가 모두 조합되면 출력
	if (depth == N)
	{
		for (int i = 0; i < N; ++i)
		{
			cout << numbers[i] << ' ';
		}
		cout << '\n';
		return true;
	}

	// 부호가 0일 때
	if (sign[depth][depth] == 0)
	{
		numbers[depth] = 0;
		return go(sign, numbers, N, depth + 1);
	}

	// 부호가 0보다 크거나 작을때
	for (int i = 1; i <= 10; ++i)
	{
		// 새로 들어올 숫자에 부호 반영
		int target = i * sign[depth][depth];
		
		// 새로 들어올 숫자가 구간별 부호 조건에 일치하는지 확인
		if (check(sign, numbers, target, depth))
		{
			numbers[depth] = target;

			// 한번이라도 조합이 완성되어 출력되면 종료
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

	// 입력
	int N;
	cin >> N;
	string s;
	cin >> s;

	// -, 0, + 부호를 -1, 0, 1 로 변환하여 벡터 저장
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

	// 백트랙킹 - 숫자 조합
	vector<int> numbers(N);
	go(sign, numbers, N, 0);

	return 0;
}