//https://www.acmicpc.net/problem/14501
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 15;
int N;
int time[MAX];
int pay[MAX];
int max_sum[MAX];

int go(int day)
{
	// 불가능한 근무 일때
	if (day > N)
	{
		return -987654321;
	}
	// 가능한 근무 일때
	if (day == N)
	{
		return 0;
	}
	// day의 최대값이 정해졌을 때
	if (max_sum[day] > 0)
	{
		return max_sum[day];
	}

	// day일에 들어온 상담을 하는 경우
	int sum1 = go(day + time[day]) + pay[day];
	
	// day일에 들어온 상담을 하지 않는 경우
	int sum2 = go(day + 1);

	// max_sum[day]에 최대값 저장 및 리턴
	return max_sum[day] = max(sum1, sum2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> time[i] >> pay[i];
		max_sum[i] = -1;
	}

	// 최대 이익 출력
	cout << go(0);

	return 0;
}