//https://www.acmicpc.net/problem/1373
#include <iostream>
#include <cmath>

using namespace std;

// 2���� -> 8����. string�� �޾Ƽ� ó���Ѵ�.
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

	// �Է°� ���̰� 3���� ������ �������� ������, 
	// �ʱ⿡ ������ ���̸�ŭ�� ���.
	int mod = input.size() % 3;
	if (mod > 0)
	{
		cout << binary_to_octal(input.substr(0, mod));
	}

	// �� �ڿ��� 3�ڸ��� �߶� ���
	for (int i = mod; i < input.size(); i += 3)
	{
		cout << binary_to_octal(input.substr(i, 3));
	}

	return 0;
}