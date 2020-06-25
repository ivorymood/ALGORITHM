//https://www.acmicpc.net/problem/1744
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long tie_n_get_sum(vector<int> &v)
{
	int len = v.size();
	long long res = 0;

	for (int i = 0; i < len; ++i)
	{
		// 다음수가 +1이 아니면 : 현재수와 다음수를 곱해서 더한다
		if (i + 1 < len && v[i + 1] != 1)
		{
			res += v[i] * v[i + 1];
			++i;
		}
		// 다음수가 없으면 : 현재수만 더한다
		else
		{
			res += v[i];
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<int> minus;
	vector<int> plus;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		// 0 초과의 수는 plus벡터에 담기
		if (num > 0)
		{
			plus.push_back(num);
		}
		// 0 이하의 수는 minus벡터에 담기
		else
		{
			minus.push_back(num);
		}
	}

	// minus벡터는 오름차순, plus벡터는 내림차순 정렬
	sort(minus.begin(), minus.end());
	sort(plus.begin(), plus.end(), [](int A, int B) {
		
		return A > B;
		});
	
	/*
		각각의 벡터를 적절히 묶고 더해 최대의 값을 구하기
		
		음수는 음수끼리, 양수는 양수끼리 곱해지므로
		묶였을 때 +값을 보장한다.
	*/
	cout << (tie_n_get_sum(minus) + tie_n_get_sum(plus));

	return 0;
}