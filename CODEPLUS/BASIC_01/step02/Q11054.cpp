//https://softworking.tistory.com/35
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	/*
		바이토닉 수열의 길이
		= max(i번째까지 "앞"에서부터 증가하는 부분수열 길이
			+ i번째까지 "뒤"에서부터 증가하는 부분수열 길이
			- 1)
	*/

	// 앞에서부터 증가하는 부분수열의 길이 구하기
	vector<int> icrs_backward(n, 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (input[j] < input[i] && icrs_backward[j] + 1 > icrs_backward[i])
			{
				icrs_backward[i] = icrs_backward[j] + 1;
			}
		}
	}

	// 뒤에서부터 증가하는 부분수열의 길이 구하기
	vector<int> icrs_forward(n, 1);
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (input[i] > input[j] && icrs_forward[j] + 1 > icrs_forward[i])
			{
				icrs_forward[i] = icrs_forward[j] + 1;
			}
		}
	}

	// 최대값 출력
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < icrs_backward[i] + icrs_forward[i] - 1)
		{
			max = icrs_backward[i] + icrs_forward[i] - 1;
		}
	}
	cout << max;

	return 0;
}