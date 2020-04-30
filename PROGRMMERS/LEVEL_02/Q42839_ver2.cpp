//https://programmers.co.kr/learn/courses/30/lessons/42839?language=cpp
//�Ҽ� ã��
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAX = 10000000;
int isno_prime[MAX + 1] = { 1, 1, };

void seive_of_eratosthenes(int max)
{
    for (int i = 2; i * i <= max; i++)
    {
        if (isno_prime[i] == false)
        {
            for (int j = 2; i * j <= max; j++)
            {
                isno_prime[i * j] = true;
            }
        }
    }
}

int solution(string numbers) {

    // �������� ����
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
        });

    // �����佺�׳׽��� ü�� �Ҽ� ���� - �ִ밪������ 
    seive_of_eratosthenes(stoi(numbers));

    // �������� ����
    sort(numbers.begin(), numbers.end());

    // �ߺ����� �ʴ� ������ �Ҽ� ã��
    set<int> prime_set;
    do
    {
        for (int i = 1; i <= numbers.size(); i++)
        {
            // ��� ������ ���� ���ϱ�
            int res = stoi(numbers.substr(0, i));

            if (!isno_prime[res])
            {
                prime_set.insert(res);
            }
        }

    } while (next_permutation(numbers.begin(), numbers.end()));

    return prime_set.size();
}

int main()
{
    string numbers;
    cin >> numbers;

    cout << solution(numbers);

    return 0;
}