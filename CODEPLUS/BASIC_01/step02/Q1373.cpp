//https://www.acmicpc.net/problem/1373
#include <iostream>
#include <cmath>

using namespace std;

// 2진수 -> 8진수. string을 받아서 처리한다.
int binary_to_octal(const string &str)
{
	int octal = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '1')
		{
			octal += pow(2, str.size() - i - 1);
		}
	}
	return octal;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input;
	cin >> input;

	// 입력값 길이가 3으로 나누어 떨어지지 않으면, 
	// 초기에 나머지 길이만큼만 계산.
	int mod = input.size() % 3;
	if (mod > 0)
	{
		cout << binary_to_octal(input.substr(0, mod));
	}

	// 그 뒤에는 3자리씩 잘라서 계산
	for (int i = mod; i < input.size(); i += 3)
	{
		cout << binary_to_octal(input.substr(i, 3));
	}

	return 0;
}