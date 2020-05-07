//https://programmers.co.kr/learn/courses/30/lessons/42885
//����Ʈ
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
   
    // �������� ����
    sort(people.begin(), people.end());
   
    // ���� ���� ���� ���� ū ������ ���
    int low = 0;
    int high = people.size() - 1;
    int cnt = 0;

    // low�� high�� �������� ����
    while (low <= high)
    {
        // ū ������ out
        high--;
        cnt++;

        // ���� �� + ū ���� limit �����̸� �������� out
        if (people[low] + people[high] <= limit)
        {
            low++;
        }
    }

    return cnt;
}

int main()
{
    /*
    vector<int> people = { 70, 50, 80, 50 };  int limit = 100;
    vector<int> people = { 60, 50, 70, 50, 40, 100 };  int limit = 100;
    vector<int> people = { 70, 80, 50 };  int limit = 100;
    */
    vector<int> people = { 70 };  int limit = 100;

    cout << solution(people, limit);

    return 0;
}