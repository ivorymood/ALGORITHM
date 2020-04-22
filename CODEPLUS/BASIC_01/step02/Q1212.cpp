//https://www.acmicpc.net/problem/1212
#include <iostream>

using namespace std;

// 8���� -> 2����. 0�� ä���� ��ȯ�Ѵ�.
string octal_to_binary(char octal)
{
	int ot = octal - '0';
	char bin[4] = {0,};
	for (int i = 0; i < 3; i++)
	{
		bin[2 - i] = ot % 2 + '0';
		ot /= 2;
	}
	return bin;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input;
	cin >> input;

	// ù��° ���ڸ� ���� ó��. 4 �̸��� ���, �̸� ������ �迭 ���
	string first[4] = { "0", "1", "10", "11" };
	if (input[0] < '4')
	{
		cout << first[input[0] - '0'];
	}
	// 4 �̻��� �� �Ϲ� ���ڿ� ���� ���
	else
	{
		cout << octal_to_binary(input[0]);

	}

	for (int i = 1; i < input.size(); i++)
	{
		cout << octal_to_binary(input[i]);
	}

	return 0;
}