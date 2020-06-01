https://www.acmicpc.net/problem/1339
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    
    // ���ĺ��� �ڸ���(����ġ)�� ������ ����
    vector<int> weight(26);
    for (int i = 0; i < N; ++i)
    {
        string word;
        cin >> word;

        int w = pow(10, word.size() - 1);
        for (char c : word)
        {
            weight[c - 'A'] += w;
            w /= 10;
        }
    }

    // �������� ����
    sort(weight.begin(), weight.end(), greater<>());

    // ����ġ * ���� �հ� ���ϱ�
    int sum = 0;
    for (int i = 0, num = 9; num >= 0; ++i, --num)
    {
        sum += weight[i] * num;
    }

    cout << sum;

    return 0;
}