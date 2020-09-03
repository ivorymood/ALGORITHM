//https://www.acmicpc.net/problem/9935
#include <iostream>
#include <deque>

using namespace std;

struct b_char {
	char c;
	int b_idx;
};

string removeBomb(string &str, string &bomb)
{
	string answer;
	deque<b_char> dq;

	// str���ڿ� Ž��
	for (char c : str)
	{
		/*
			c�� bomb�� ù��° or deque�� back�� �ε��� + 1��° ���ڰ� �ƴϸ�
			-> answer ���ڿ��� push
		*/
		if (!(c == bomb[0] || (!dq.empty() && c == bomb[dq.back().b_idx + 1])))
		{
			// deque�� ��� ���ڵ��� answer�� �����̱�
			while (!dq.empty())
			{
				answer.push_back(dq.front().c);
				dq.pop_front();
			}

			answer.push_back(c);
			continue;
		}

		// deqeu�� {����, bomb�� �ε�����} push
		int idx = (c == bomb[0] ? 0 : dq.back().b_idx + 1);
		dq.push_back({c, idx});

		/*
			deque�� back�� �ε��� + 1���� bomb���ڿ� ������� ������
			-> bomb������ ��ŭ deque���� �����
		*/
		if (dq.back().b_idx + 1 == bomb.size())
		{
			int cnt = bomb.size();
			while (cnt-- > 0)
			{
				dq.pop_back();
			}
		}
	}

	// ���������� deque�� ���� ���ڵ��� answer�� �����̱�
	while (!dq.empty())
	{
		answer.push_back(dq.front().c);
		dq.pop_front();
	}

	return answer.size() == 0 ? "FRULA" : answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	string str, bomb;
	cin >> str >> bomb;

	// bomb ���ڿ��� ��� ������ ��� ���
	cout << removeBomb(str, bomb);

	return 0;
}