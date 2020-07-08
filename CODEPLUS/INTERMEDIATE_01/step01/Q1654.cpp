//https://www.acmicpc.net/problem/1654
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_possible_line(vector<int> &lines, long long len)
{
	int cnt = 0;
	for (int i = 0; i < lines.size(); ++i)
	{
		cnt += lines[i] / len;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int K, N;
	cin >> K >> N;
	vector<int> lines(K);
	for (int i = 0; i < K; ++i)
	{
		cin >> lines[i];
	}

	// 이분탐색
	long long answer = 0;
	long long left = 1;
	long long right = *max_element(lines.begin(), lines.end());

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		int cnt = count_possible_line(lines, mid);

		// 개수가 N이상이면 더 크게 자를수 있는지 확인해야 함
		if (cnt >= N)
		{
			// 자르는 크기 최대값 갱신
			answer = max(mid, answer);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	// 출력
	cout << answer;

	return 0;
}