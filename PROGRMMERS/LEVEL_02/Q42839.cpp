//https://programmers.co.kr/learn/courses/30/lessons/42839?language=cpp
//�Ҽ� ã��
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10000000;
int isno_prime[MAX + 1] = {1, 1, };
int bf;
int cnt;

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

// nCr ������ �� ��� ���ϱ�
void perm(const string &numbers, string output, bool visited[], int depth, int r)
{
    if (depth == r)
    {
        int res = stoi(output);
        // numbers�� �������� ���ĵǾ����Ƿ�, ���� ���ں��� ū ���� ī�����ص� OK
        if (bf < res && !isno_prime[res])
        {
            bf = res;
            cnt++;
        }
        return;
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            perm(numbers, output + numbers[i], visited, depth + 1, r);
            visited[i] = false;
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

    // nCr(1 <= r <= n) ������ ��츦 ��� ����ϸ�
    // ���ü� �ִ� �Ҽ� ���ϱ�
    const int MAX_SIZE = 7;
    bool visited[MAX_SIZE] = {0,};
    for (int i = 1; i <= numbers.size(); i++)
    {
        perm(numbers, "", visited, 0, i);
    }

    return cnt;
}

int main()
{
    string numbers;
    cin >> numbers;

    cout << solution(numbers);

    return 0;
}