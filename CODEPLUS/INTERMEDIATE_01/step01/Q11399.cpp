//https://www.acmicpc.net/problem/11399
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<int> times(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> times[i];
	}

	// 오름차순 정렬
	sort(times.begin(), times.end());

	// 각각의 기다린 시간 총합 구하기
	int total = 0, sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += times[i];
		total += sum;
	}

	cout << total;

	return 0;
}