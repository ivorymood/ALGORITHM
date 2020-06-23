//https://programmers.co.kr/learn/courses/30/lessons/43238
//�Ա��ɻ�
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

typedef long long ll;

// t�ð� ���� ��ǥ�� ������� ��� �ɻ��� �� ������ true ��ȯ
bool possible(vector<int>& times, ll t, int target)
{
    ll passed = 0;
    for (int i = 0; i < times.size(); ++i)
    {
        passed += t / times[i];
    }
    return (passed >= target);
}

ll search(vector<int>& times, ll start, ll end, ll target, ll answer)
{
    // ���� ���� > ������ ���� �� ��, ������ ���� ��ȯ
    if (start > end)
    {
        return answer;
    }

    // mid���� ����ϸ� (=mid�ð� ���� �־��� ������� ��� �ɻ��� �� ������)
    // : ������ ������ �߰��� - 1�� search ����Լ� ȣ��
    ll mid = (start + end) / 2;
    if (possible(times, mid, target))
    {
        answer = min(mid, answer);
        return search(times, start, mid - 1, target, answer);
    }
    // mid���� �ʹ� ������ : ���� ������ �߰��� + 1�� search ����Լ� ȣ��
    else
    {
        return search(times, mid + 1, end, target, answer);
    }
}

ll solution(int n, vector<int> times) {

    // �������� ����
    sort(times.begin(), times.end());

    // �־��� ��� �� n�� ���� �ɻ��ϴ� ���� �ּ�, �ִ�� �ɸ��� �ð�
    ll low = ((ll)n * times.front()) / times.size();
    ll high = (ll)n * (ll)times.back();

    /*
        �̺�Ž������ ��� ����� �ɻ縦 ���� �� �ִ�
        ������ �ּ��� �ð� ���ϱ�
    */
    return search(times, low, high, n, numeric_limits<ll>::max());
}

int main()
{
    int n = 1000000000; vector<int> times = { 1, 1000000000, 1000000000 }; //1000000000
    /*
    int n = 6; vector<int> times = {8, 10}; // 30
    int n = 6; vector<int> times = {7, 10}; // 28
    int n = 6; vector<int> times = {6, 10}; // 24
    int n = 6; vector<int> times = {4, 10}; // 20
    int n = 11; vector<int> times = {3, 4, 10}; // 18
    int n = 5; vector<int> times = {3, 5, 7};
    int n = 1000000005; vector<int> times = { 1, 1000000000, 1000000000 }; //1000000000
    */

    cout << solution(n, times);

    return 0;
}