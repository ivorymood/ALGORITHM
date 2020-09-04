//https://www.acmicpc.net/problem/16916
#include <iostream>
#include <vector>

using namespace std;

// Prefix Index �迭 �����
vector<int> make_pi(string &pattern)
{
	int len = pattern.size();
	vector<int> pi(len);

	for (int i = 1, j = 0; i < len; ++i)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = pi[j - 1];
		}

		if (pattern[i] == pattern[j])
		{
			pi[i] = ++j;
		}
	}
	return pi;
}

// kmp �˰������� pattern�� parent�� �����ϴ��� ���� �Ǻ�
bool kmp(string &parent, string &pattern)
{
	vector<int> pi = make_pi(pattern);
	int parent_size = parent.size();
	int pattern_size = pattern.size();

	for (int i = 0, j = 0; i < parent_size; ++i)
	{
		while (j > 0 && parent[i] != pattern[j])
		{
			j = pi[j - 1];
		}

		if (parent[i] == pattern[j])
		{
			if (j == pattern_size - 1)
			{
				return true;
			}
			else
			{
				++j;
			}
		}
	}
	return false;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	string parent, pattern;
	cin >> parent >> pattern;

	// ���Կ��� ��� - kmp �˰���
	cout << kmp(parent, pattern);

	return 0;
}