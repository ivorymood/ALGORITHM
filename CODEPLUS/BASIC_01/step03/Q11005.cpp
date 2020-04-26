//https://www.acmicpc.net/problem/11005
#include <iostream>
#include <algorithm>

using namespace std;

string get_xbase_num(int n, int x)
{
	// 0~35까지의 숫자
	string nums = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string ans = "";

	while (n > 0)
	{
		ans += nums[n % x];
		n /= x;
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, B;
	cin >> N >> B;

	cout << get_xbase_num(N, B);

	return 0;
}