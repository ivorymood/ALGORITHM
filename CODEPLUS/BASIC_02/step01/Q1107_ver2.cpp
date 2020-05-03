//https://www.acmicpc.net/problem/1107
// 로직만 참고해야 하는 풀이입니다.
// BOJ 채점시 런타임오류

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int cnt;

void perm(const string& numbers, string output, int depth, int r)
{
	if (depth == r)
	{
		// 목표 채널보다 1자리 적은 수 ~ 1자리 많은 수 체크
		for (int i = 0; i < 3; i++)
		{
			if (r - i >= 0)
			{
				int res = stoi(output.substr(0, r - i));
				
				// 버튼 누른 총 횟수 : 가장 가까운 채널 길이 + (+/-) 버튼 누른 횟수
				if (cnt > abs(res - N) + to_string(res).size())
				{
					cnt = abs(res - N) + to_string(res).size();
				}
			}
		}

		return;
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		perm(numbers, output + numbers[i], depth + 1, r);
	}
}

int broken_cnt(int N, bool is_broken[])
{
	int cnt = 0;
	do
	{
		if (is_broken[N % 10])
		{
			cnt++;
		}
		N /= 10;
	} while (N);
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int now = 100;

	// 입력
	int M;
	cin >> N >> M;
	bool is_broken[10] = { 0, };

	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		is_broken[tmp] = true;
	}

	// 목표 채널이 현재 채널이거나, 모든 숫자버튼이 고장났을 때
	if (abs(N - now) == 0 || M == 10)
	{
		cout << abs(N - now);
		return 0;
	}
	// 만들려는 채널 숫자에 해당하는 고장난 버튼이 없을때
	if (broken_cnt(N, is_broken) == 0)
	{
		cout << min((int)to_string(N).size(), abs(N - now));
		return 0;
	}

	// 정상 버튼 문자열 만들기
	string numbers;
	for (int i = 0; i < 10; i++)
	{
		if (!is_broken[i])
		{
			numbers.push_back((char)i + '0');
		}
	}

	// 정상버튼으로 목표채널과 가장 가까운 채널 만들기
	cnt = abs(N - now);
	
	perm(numbers, "", 0, to_string(N).size() + 1);

	cout << cnt;

	return 0;
}