//https://www.acmicpc.net/problem/2089
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	// 0일경우 예외처리
	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	stack<int> s_mbin;
	while (n != 0)
	{
		int quot = n / -2;

		// 나머지가 없을 때
		if (n % -2 == 0)
		{
			s_mbin.push(0);
			n = quot;
		}
		// 나머지가 있을 때
		else
		{
			// ex) -13 / -2 = 6 ... 1 인데,
			//     -2 * (6 + 1) + 1 = -13 처럼 원상복귀 할때 몫에 1이 더 필요한 경우
			if (n < 0)
			{
				n = quot + 1;
			}
			// ex) 7 / -2 = -3 ... 1 인데,
			//    -2 * -3 + 1 = 7의 경우
			else
			{
				n = quot;
			}
			s_mbin.push(1);
		}
	}

	while (!s_mbin.empty())
	{
		cout << s_mbin.top();
		s_mbin.pop();
	}

	return 0;
}