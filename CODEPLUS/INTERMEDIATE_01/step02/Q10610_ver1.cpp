//https://www.acmicpc.net/problem/10610
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	string num;
	cin >> num;
	
	// �������� ����
	sort(num.begin(), num.end(), [](char A, char B) {
		return A > B;
		});

	// �� �ڸ������� �� ���ϱ�
	int sum = 0;
	for (int i = 0; i < num.size(); ++i)
	{
		sum += num[i] - '0';
	}

	// ���� 3���� ������ �������� �ʰų�, �� ���ڸ��� 0�� �ƴϸ� ����
	if (sum % 3 != 0 || num.back() != '0')
	{
		cout << -1;
	}
	else
	{
		cout << num;
	}

	return 0;
}