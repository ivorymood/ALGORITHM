//https://www.acmicpc.net/problem/1759
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// �ּ� ���� 1��, ���� 2�� ���ǿ� �����ϴ��� �˻�
bool check(string pw)
{
	const string consonant = "aeiou";

	int c_cnt = 0;
	for (char c : pw)
	{
		if (consonant.find(c) != string::npos)
		{
			++c_cnt;
		}
	}

	return (c_cnt >= 1 && pw.length() - c_cnt >= 2);
}

void dfs(vector<char> &chars, string pw, int L, int index)
{
	// L�ڸ��� �ϼ��Ǹ� ���
	if (pw.length() == L)
	{
		if (check(pw))
		{
			cout << pw << '\n';
		}
		return;
	}
	// L�ڸ��� �ϼ��Ǳ� ���� index�� ������ �Ѿ���� ���
	else if (index == chars.size())
	{
		return;
	}

	// chars[index]�� �����ϴ� ���
	dfs(chars, pw + chars[index], L, index + 1);

	// chars[index]�� �������� �ʴ� ���
	dfs(chars, pw, L, index + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int L, C;
	cin >> L >> C;
	vector<char> chars(C);
	for (int i = 0; i < C; ++i)
	{
		cin >> chars[i];
	}
	// �������� ����
	sort(chars.begin(), chars.end());

	// dfs - ��Ʈ��ŷ���� ���� ����
	dfs(chars, "", L, 0);

	return 0;
}