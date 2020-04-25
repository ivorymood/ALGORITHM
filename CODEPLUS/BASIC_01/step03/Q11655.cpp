//https://www.acmicpc.net/problem/11655
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	string input;
	getline(cin, input);

	// A/a ~ Z/z를 0 ~ 25로 인덱스를 잡고, 
	// 인덱스가 26이 넘으면 다시 0부터 시작.
	for (int i = 0; i < input.size(); i++)
	{
		if ('A' <= input[i] && input[i] <= 'Z')
		{
			input[i] = (input[i] - 'A' + 13) % 26 + 'A';
		}
		else if ('a' <= input[i] && input[i] <= 'z')
		{
			input[i] = (input[i] - 'a' + 13) % 26 + 'a';
		}
	}

	cout << input;

	return 0;
}