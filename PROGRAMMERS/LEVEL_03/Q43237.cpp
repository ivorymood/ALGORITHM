//https://programmers.co.kr/learn/courses/30/lessons/43237
//����
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int get_limited_sum(vector<int> &budgets, int limit)
{
    int sum = 0;
    for (auto iter = budgets.begin(); iter != budgets.end(); ++iter)
    {
        // ��û���� limit���� ũ�� sum�� limit���� ��� �����ֱ�
        if (*iter > limit)
        {
            sum += limit;
        }
        else 
        {
            sum += *iter;
        }
    }
    return sum;
}

int search(vector<int> &budgets, int start, int end, int target)
{
    // ���� ���� > ������ ���� �� ��, ������ ���� ��ȯ
    if (start > end)
    {
        return end;
    }

    // �߰����� limit���� ���� �� �� ��û�� ���ϱ�
    int mid = (start + end) / 2;
    int sum = get_limited_sum(budgets, mid);

    // ��û�� == ��ǥ ������ : limit�� ��ȯ
    if (sum == target)
    {
        return mid;
    }
    // limit�� �ʹ� ū ��� : ������ ������ �߰��� -1�� search ����Լ� ȣ��
    else if (sum > target)
    {
        return search(budgets, start, mid - 1, target);
    }
    // limit�� �ʹ� ���� ��� : ���� ������ �߰��� +1�� search ����Լ� ȣ��
    else 
    {
        return search(budgets, mid + 1, end, target);
    }
}

int solution(vector<int> budgets, int M) {

    // �̺�Ž�� �ּ�, �ִ� ���۰��� ���ϱ� ���� �������� ����
    sort(budgets.begin(), budgets.end());

    /*
        ��� ��û�� ������ �� ���� ��쵵 ���� �� �����Ƿ�
        (�� ���� / ���� ����)�� �ּ� ���� ��û���� ���ؼ� 
        �� ���� ������ �̺�Ž���� �����Ѵ�.
    */
    int len = budgets.size();
    int min_start = min(budgets.front(), M / len);

    return search(budgets, min_start, budgets.back(), M);
}

int main()
{
    /*
    vector<int> budgets = { 120, 110, 140, 150 }; int M = 485;
    
    */
    vector<int> budgets = {5, 6, 7, 8, 9}; int M = 5;

    cout << solution(budgets, M);

    return 0;
}