//https://www.acmicpc.net/problem/10808
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
    for (int i = 'a'; i <= 'z'; i++)
    {
        // �ݺ��� ����Ͽ� i ���� ����
        cout << count(s.begin(), s.end(), i) << ' ';
    }
    return 0;
}
