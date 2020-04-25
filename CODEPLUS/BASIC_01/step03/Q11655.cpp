//https://www.acmicpc.net/problem/11655
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	string input;
	getline(cin, input);

	// A/a ~ Z/z�� 0 ~ 25�� �ε����� ���, 
	// �ε����� 26�� ������ �ٽ� 0���� ����.
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