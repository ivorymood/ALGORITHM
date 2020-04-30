//https://programmers.co.kr/learn/courses/30/lessons/42839?language=cpp
//소수 찾기
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

// nCr 가지의 수 모두 구하기
void perm(const string &numbers, string output, bool visited[], int depth, int r)
{
    if (depth == r)
    {
        int res = stoi(output);
        // numbers가 오름차순 정렬되었으므로, 이전 숫자보다 큰 수만 카운팅해도 OK
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

    // 내림차순 정렬
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
        });

    // 에라토스테네스의 체로 소수 구분 - 최대값까지만 
    seive_of_eratosthenes(stoi(numbers));
    
    // 오름차순 정렬
    sort(numbers.begin(), numbers.end());

    // nCr(1 <= r <= n) 가지의 경우를 모두 계산하며
    // 나올수 있는 소수 구하기
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