//https://www.acmicpc.net/problem/12919
#include <iostream>
#include <algorithm>

using namespace std;

// 첫번째 연산 원복하기
string rule_1(string str)
{
	str.pop_back();
	return str;
}

// 두번째 연산 원복하기
string rule_2(string str)
{
	reverse(str.begin(), str.end());
	str.pop_back();
	return str;
}

bool change(string from, const string &to)
{
	// 두 문자열이 동일하면 true반환
	if (from.compare(to) == 0)
	{
		return true;
	}
	// 규칙으로 만들어질수 없는 경우이거나, 두 문자열이 같지 않은데 길이가 서로 같으면 false 반환
	if (from.front() == 'A' && from.back() == 'B' || from.size() <= to.size())
	{
		return false;
	}

	// from의 맨 뒤가 'A'이고, 첫번째 연산을 원복한 문자열로 change재귀함수 돌린 결과가 true이면
	if (from.back() == 'A' && change(rule_1(from), to))
	{
		return true;
	}
	// from의 맨 앞이 'B'이고, 두번째 연산을 원복한 문자열로 change재귀함수 돌린 결과가 true이면
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
		접근방식 : 두번째 문자열을 원복시켜서 첫번째 문자열로 만들수 있는지 확인하기
	*/
	string to, from;
	cin >> to >> from;

	cout << change(from, to);

	return 0;
}