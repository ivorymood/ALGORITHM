//https://www.acmicpc.net/problem/10820
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input;
	while (getline(cin, input))
	{
		int lower = 0;
		int upper = 0;
		int number = 0;
		int space = 0;

		for (char ch : input)
		{
			if ('a' <= ch && ch <= 'z')
			{
				lower++;
			}
			else if ('A' <= ch && ch <= 'Z')
			{
				upper++;
			}
			else if ('0' <= ch && ch <= '9')
			{
				number++;
			}
			else if (ch == ' ')
			{
				space++;
			}
		}

		cout << lower << ' ' << upper << ' ' << number << ' ' << space << '\n';
	}

	return 0;
}