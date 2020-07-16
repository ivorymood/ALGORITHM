//https://www.acmicpc.net/problem/1561
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll N_MAX = 2000000000LL;
const ll T_MAX = 30;
ll N, M;

// 주어진 time시간까지 놀이기구를 탄 아이들 수 구하기
ll cnt_passed(vector<ll> &rides, ll time)
{
	// 0분에는 모든 놀이기구가 비어있으므로, sum은 M부터 시작
	ll sum = M;
	for (int i = 0; i < M; ++i)
	{
		// 해당 시각까지 놀이기구를 탄 아이들 수 카운팅
		sum += time / rides[i];
	}
	return sum;
}

void binary_search(vector<ll>& rides, ll &now, ll& passed)
{
	ll left = 0;
	ll right = N_MAX * T_MAX; // 최대 아이들 수 * 최대 놀이기구 시간

	while (left <= right)
	{
		// passed : mid시각까지 놀이기구를 탄 아이들 수
		ll mid = (left + right) / 2;
		ll cnt = cnt_passed(rides, mid);

		if (cnt >= N)
		{
			// now : 마지막 아이가 놀이기구를 타는 시간대
			now = mid;
			right = mid - 1;
		}
		else
		{
			// passed_bf : mid시각 전까지 놀이기구를 탄 아이들 수
			passed = cnt;
			left = mid + 1;
		}
	}
}

int get_ride_num(vector<ll> &rides, ll now, ll passed)
{
	for (int i = 0; i < M; ++i)
	{
		// now에 비어있는 놀이기구가 있다면
		if (now % rides[i] == 0)
		{
			++passed;

			// 놀이기구를 탄 아이들 수가 N이면, 해당 놀이기구 번호 반환
			if (passed == N)
			{
				return i + 1;
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> N >> M;
	vector<ll> rides(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> rides[i];
	}

	/*
		아이들 수가 놀이기구 수보다 적을 때 
		: 마지막 아이는 N번째 놀이기구를 탄다
	*/
	if (N <= M)
	{
		cout << N;
	}
	else
	{
		/*
			now : 마지막 아이가 놀이기구를 타는 시각
			passed : now 시각 전까지 놀이기구를 탄 아이들 수
			
			이분탐색으로 now와 passed를 구한다
		*/
		ll now = 0, passed = 0;
		binary_search(rides, now, passed);

		cout << get_ride_num(rides, now, passed);
	}
	 
	return 0;
}