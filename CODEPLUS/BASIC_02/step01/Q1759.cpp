//https://www.acmicpc.net/problem/1759
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 최소 모음 1개, 자음 2개 조건에 만족하는지 검사
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
	// L자리가 완성되면 출력
	if (pw.length() == L)
	{
		if (check(pw))
		{
			cout << pw << '\n';
		}
		return;
	}
	// L자리가 완성되기 전에 index가 범위를 넘어버린 경우
	else if (index == chars.size())
	{
		return;
	}

	// chars[index]를 선택하는 경우
	dfs(chars, pw + chars[index], L, index + 1);

	// chars[index]를 선택하지 않는 경우
	dfs(chars, pw, L, index + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int L, C;
	cin >> L >> C;
	vector<char> chars(C);
	for (int i = 0; i < C; ++i)
	{
		cin >> chars[i];
	}
	// 오름차순 정렬
	sort(chars.begin(), chars.end());

	// dfs - 백트랙킹으로 문자 조합
	dfs(chars, "", L, 0);

	return 0;
}