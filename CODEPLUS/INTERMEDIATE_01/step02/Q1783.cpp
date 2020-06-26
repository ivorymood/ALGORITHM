//https://www.acmicpc.net/problem/1783
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է� : �� / ��
	int height, width;
	cin >> height >> width;
	
	if (height == 1)
	{
		cout << 1;
	}
	else if (height == 2)
	{
		// �̵� ��� ���� ���� : �湮������ 5 �̻��̷��� ��� �̵� ����� ����� ���¿��� ��
		cout << min(4, (width + 1) / 2);
	}
	else 
	{
		if (width < 7)
		{
			// �̵� ��� ���� ���� : �湮������ 5 �̻��̷��� ��� �̵� ����� ����� ���¿��� ��
			cout << min(4, width);
		}
		else 
		{
			// �̵� ��� ���� ���� 
			// : �ּ� 1������ ���������� 2ĭ �̵��ϴ� ����� �����
			cout << width - 2;
		}
	}

	return 0;
}