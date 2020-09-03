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

	// str문자열 탐색
	for (char c : str)
	{
		/*
			c가 bomb의 첫번째 or deque의 back의 인덱스 + 1번째 문자가 아니면
			-> answer 문자열에 push
		*/
		if (!(c == bomb[0] || (!dq.empty() && c == bomb[dq.back().b_idx + 1])))
		{
			// deque에 담긴 문자들을 answer에 덧붙이기
			while (!dq.empty())
			{
				answer.push_back(dq.front().c);
				dq.pop_front();
			}

			answer.push_back(c);
			continue;
		}

		// deqeu에 {문자, bomb의 인덱스값} push
		int idx = (c == bomb[0] ? 0 : dq.back().b_idx + 1);
		dq.push_back({c, idx});

		/*
			deque의 back의 인덱스 + 1값이 bomb문자열 사이즈와 같으면
			-> bomb사이즈 만큼 deque에서 덜어내기
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

	// 마지막으로 deque에 남은 문자들을 answer에 덧붙이기
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

	// 입력
	string str, bomb;
	cin >> str >> bomb;

	// bomb 문자열을 모두 삭제한 결과 출력
	cout << removeBomb(str, bomb);

	return 0;
}