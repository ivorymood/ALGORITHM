//https://programmers.co.kr/learn/courses/30/lessons/12936
//줄 서는 방법
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
        팩토리얼 배열 만들기. 
        NaN 방지를 위해 0번째 값을 1로 저장해준다.
    */
    vector<long long> fact(n + 1);
    make_factorial(fact, n);
    fact[0] = 1;

    // [1, n]이 저장된 숫자 배열 만들기
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        nums[i] = i + 1;
    }

    
    /*
        순열에서 i번째 숫자를 정할 때,
        k가 n - 1자리의 순열을 qe개 가질수 있다면
        i번째 자리 숫자는 현재 남은 숫자 중에서 qe번째로 큰 수 이다.
    */
    --k;
    vector<int> answer;
    while (n--)
    {
        // k를 (n - 1)!로 나누었을 때의 몫과 나머지
        int qe = k / fact[n];
        k %= fact[n];

        // 현재 남은 숫자중에서 qe번째로 큰 수 push
        answer.push_back(nums[qe]);

        // 사용한 숫자는 지워준다.
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