//https://www.acmicpc.net/problem/2138
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

// idx - 1, idx, idx + 1�� ���� ���¸� ������
void flip(string& s, int idx)
{
	for (int i = idx - 1; i <= idx + 1; ++i)
	{
		if (i < 0 || i >= s.size())
		{
			continue;
		}

		if (s[i] == '0')
		{
			s[i] = '1';
		}
		else
		{
			s[i] = '0';
		}
	}
}

int get_flip_cnt(string from, const string& to, int N, bool flag)
{
	int cnt = 0;
	
	/*
		���� ó���� ��ġ���� ������ �������� ������ ����
		�� ���� ���� �����Ⱑ �����ǹǷ�
		ó�� ��ġ���� ���� �����°�� / �� ������ ��� 2�� �Ǵ��� �־�� ��.
	*/
	if (flag)
	{
		flip(from, 0);
		++cnt;
	}

	// i - 1��° �������¸� �������� ���������  (�ι�° ��������)
	for (int i = 1; i < N; ++i)
	{
		if (from[i - 1] != to[i - 1])
		{
			flip(from, i);
			++cnt;
		}
	}

	// ������ ������ �ٸ��� ����
	if (from[N - 1] != to[N - 1])
	{
		cnt = INF;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	string from, to;
	cin >> from >> to;

	// ó�� ��ġ���� ���� �����°�� / �� ������ ����� Ƚ���� ���� ����Ͽ�, �� ������ ���
	int answer = min(get_flip_cnt(from, to, N, true), get_flip_cnt(from, to, N, false));
	
	cout << ((answer == INF) ? -1 : answer);

	return 0;
}