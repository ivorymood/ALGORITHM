//https://www.acmicpc.net/problem/10824
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A, B, C, D;
	cin >> A >> B >> C >> D;

	string s1 = to_string(A).append(to_string(B));
	string s2 = to_string(C).append(to_string(D));

	// (1 �� A, B, C, D �� 1,000,000) �̹Ƿ�, 
	// �� ���� �̾���̸� int ������ �Ѵ´� -> long long ��ȯ
	cout << stoll(s1) + stoll(s2);

	return 0;
}