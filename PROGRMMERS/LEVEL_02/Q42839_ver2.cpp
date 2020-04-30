//https://programmers.co.kr/learn/courses/30/lessons/42839?language=cpp
//소수 찾기
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

    // 내림차순 정렬
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
        });

    // 에라토스테네스의 체로 소수 구분 - 최대값까지만 
    seive_of_eratosthenes(stoi(numbers));

    // 오름차순 정렬
    sort(numbers.begin(), numbers.end());

    // 중복되지 않는 조합의 소수 찾기
    set<int> prime_set;
    do
    {
        for (int i = 1; i <= numbers.size(); i++)
        {
            // 모든 길이의 숫자 구하기
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