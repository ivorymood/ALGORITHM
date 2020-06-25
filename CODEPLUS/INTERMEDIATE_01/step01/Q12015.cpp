//https://www.acmicpc.net/problem/12015
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	/*
		가장 긴 증가하는 수열 만들기
		앞쪽에 더 큰 수가 없으면 새로운 값을 LIS수열 뒤에 이어붙이고
		더 큰수가 있다면 그 자리를 새로운 값으로 대체한다.
	*/
	vector<int> LIS;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;

		// LIS벡터에서 num보다 같거나 큰 수의 위치 찾기
		auto it = lower_bound(LIS.begin(), LIS.end(), num);

		// num보다 같거나 큰 수가 없다면 : LIS의 끝에 num push
		if (it == LIS.end())
		{
			LIS.push_back(num);
		}
		// num보다 같거나 큰 수가 있으면 : num으로 대체
 		else
		{
			*it = num;
		}
	}

	cout << LIS.size();

	return 0;
}