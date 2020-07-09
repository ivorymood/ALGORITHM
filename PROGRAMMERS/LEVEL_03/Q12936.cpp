//https://programmers.co.kr/learn/courses/30/lessons/12936
//�� ���� ���
#include <iostream>

#include <string>
#include <vector>

using namespace std;

long long make_factorial(vector<long long>& fact, long long num)
{
    if (num < 1)
    {
        return 1;
    }
    if (fact[num] > 0)
    {
        return fact[num];
    }

    return fact[num] = make_factorial(fact, num - 1) * num;
}

vector<int> solution(int n, long long k) {
   
    /*
        ���丮�� �迭 �����. 
        NaN ������ ���� 0��° ���� 1�� �������ش�.
    */
    vector<long long> fact(n + 1);
    make_factorial(fact, n);
    fact[0] = 1;

    // [1, n]�� ����� ���� �迭 �����
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        nums[i] = i + 1;
    }

    
    /*
        �������� i��° ���ڸ� ���� ��,
        k�� n - 1�ڸ��� ������ qe�� ������ �ִٸ�
        i��° �ڸ� ���ڴ� ���� ���� ���� �߿��� qe��°�� ū �� �̴�.
    */
    --k;
    vector<int> answer;
    while (n--)
    {
        // k�� (n - 1)!�� �������� ���� ��� ������
        int qe = k / fact[n];
        k %= fact[n];

        // ���� ���� �����߿��� qe��°�� ū �� push
        answer.push_back(nums[qe]);

        // ����� ���ڴ� �����ش�.
        nums.erase(nums.begin() + qe);
    }

    return answer;
}

int main()
{
    int n = 3; int k = 5;
    vector<int> res = solution(n, k);

    for (int n : res)
    {
        cout << n << ' ';
    }

    return 0;
}