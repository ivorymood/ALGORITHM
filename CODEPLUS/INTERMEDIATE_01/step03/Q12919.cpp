//https://www.acmicpc.net/problem/12919
#include <iostream>
#include <algorithm>

using namespace std;

// ù��° ���� �����ϱ�
string rule_1(string str)
{
	str.pop_back();
	return str;
}

// �ι�° ���� �����ϱ�
string rule_2(string str)
{
	reverse(str.begin(), str.end());
	str.pop_back();
	return str;
}

bool change(string from, const string &to)
{
	// �� ���ڿ��� �����ϸ� true��ȯ
	if (from.compare(to) == 0)
	{
		return true;
	}
	// ��Ģ���� ��������� ���� ����̰ų�, �� ���ڿ��� ���� ������ ���̰� ���� ������ false ��ȯ
	if (from.front() == 'A' && from.back() == 'B' || from.size() <= to.size())
	{
		return false;
	}

	// from�� �� �ڰ� 'A'�̰�, ù��° ������ ������ ���ڿ��� change����Լ� ���� ����� true�̸�
	if (from.back() == 'A' && change(rule_1(from), to))
	{
		return true;
	}
	// from�� �� ���� 'B'�̰�, �ι�° ������ ������ ���ڿ��� change����Լ� ���� ����� true�̸�
	if (from.front() == 'B' && change(rule_2(from), to))
	{
		return true;
	}
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	/*
		���ٹ�� : �ι�° ���ڿ��� �������Ѽ� ù��° ���ڿ��� ����� �ִ��� Ȯ���ϱ�
	*/
	string to, from;
	cin >> to >> from;

	cout << change(from, to);

	return 0;
}