//https://www.acmicpc.net/problem/10809
#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	for (int i = 'a'; i <= 'z' ; i++)
	{
		// i�� ��ġ�� �ݺ��� ã��
		auto it = find(s.begin(), s.end(), i);
		
		// ��ã������
		if (it == s.end())
		{
			cout << -1 << ' ';
		}
		else
		{
			cout << (it - s.begin()) << ' ';
		}
	}

	return 0;
}