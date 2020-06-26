//https://www.acmicpc.net/problem/12904
#include <iostream>
#include <algorithm>

using namespace std;

bool change(string &from, const string &to)
{
	// from 문자열이 to문자열과 길이가 같아질 때까지
	while (from.length() > to.length())
	{
		// 맨 뒤가 A면 : 연산 1 원복
		if (from.back() == 'A')
		{
			from.pop_back();
		}
		// 맨 뒤가 B면 : 연산 2 원복
		else
		{
			from.pop_back();
			reverse(from.begin(), from.end());
		}
	}

	// 두 문자열이 같으면 true
	return from.compare(to) == 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string to, from;
	cin >> to >> from;

	cout << change(from, to);

	return 0;
}