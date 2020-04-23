//https://www.acmicpc.net/problem/13398
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
	vector<int> input(n + 2);	// 양 끝에 1칸씩 여유를 둔다. 
	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}

	/*
		DL[i] : 왼쪽에서부터 i에서의 최대 연속합
		DR[i] : 오른쪽에서부터 i에서의 최대 연속합
	*/
	vector<int> DL(n + 2);
	vector<int> DR(n + 2);
	for (int i = 1; i <= n; i++)
	{
		DL[i] = input[i];
		DR[n - i + 1] = input[n - i + 1];

		if (DL[i - 1] >= 0)
		{
			DL[i] += DL[i - 1];
		}
		if (DR[n - i + 2] >= 0)
		{
			DR[n - i + 1] += DR[n - i + 2];
		}
	}

	// 수를 제거하지 않았을 때 최대값 구하기
	// 수는 반드시 한개 이상 선택해야 하기 때문에 초기값 = DL[1]
	int max = DL[1];
	for (int i = 2; i <= n; i++)
	{
		if (max < DL[i])
		{
			max = DL[i];
		}
	}

	/*
		수를 제거했을 때 최대값 구하기

		i번째 수를 제거했을 때, i번째 수가 포함되는 최대 연속합
		--> DL[i - 1] + DR[i + 1]
	*/
	for (int i = 2; i <= n; i++)
	{
		if (max < DL[i - 1] + DR[i + 1])
		{
			max = DL[i - 1] + DR[i + 1];
		}
	}
	cout << max;

	return 0;
}