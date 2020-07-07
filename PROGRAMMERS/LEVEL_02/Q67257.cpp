//https://programmers.co.kr/learn/courses/30/lessons/67257
//수식 최대화
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

void classify_nums_ops(string &exp, vector<long long> &nums, vector<char> &ops)
{
    long long num = 0;
    for (int i = 0; i < exp.size(); ++i)
    {
        // 현재 문자가 숫자일 때
        if (exp[i] >= '0')
        {
            num *= 10;
            num += exp[i] - '0';
        }
        // 현재 문자가 연산자일 때
        else
        {
            nums.push_back(num);
            ops.push_back(exp[i]);

            num = 0;
        }
    }

    nums.push_back(num);
}

long long cal(long long num1, long long num2, char op)
{
    if (op == '+')
    {
        return num1 + num2;
    }
    else if (op == '-')
    {
        return num1 - num2;
    }
    else if (op == '*')
    {
        return num1 * num2;
    }
    return -1;
}

long long solution(string expression) {

    // 숫자 배열과 연산자 배열 만들기
    vector<long long> nums;
    vector<char> ops;
    classify_nums_ops(expression, nums, ops);

    // 3개 연산자의 순열을 위한 문자열 생성 후 정렬
    string op_order = "+-*";
    sort(op_order.begin(), op_order.end());


    long long answer = 0;
    do 
    {
        /*
            숫자열과 연산자열을 q1에 저장.
            q2는 1차례 계산 후의 숫자열과 연산자열이 저장될 큐
        */
        queue<long long, deque<long long>> num_q2, num_q1(deque<long long>(nums.begin(), nums.end()));
        queue<char, deque<char>> op_q2, op_q1(deque<char>(ops.begin(), ops.end()));

        for (int i = 0; i < 3; ++i)
        {
            // last : 중간에 계산된 숫자를 저장
            long long last = num_q1.front();
            num_q1.pop();

            while (!op_q1.empty())
            {
                // 해당순위 연산자일 때 : 숫자 연산한 값을 last에 저장
                if (op_q1.front() == op_order[i])
                {
                    last = cal(last, num_q1.front(), op_q1.front());
                }
                // 해당순위 연산자가 아닐 때 : last를 q2에 저장 후, q1의 다음 숫자로 교체
                else
                {
                    op_q2.push(op_q1.front());
                    num_q2.push(last);
                    
                    last = num_q1.front();
                }

                op_q1.pop();
                num_q1.pop();
            }
            num_q2.push(last);

            // 마지막에 남은 숫자큐의 원소가 1개일 때 : 최대 절대값 갱신
            if (num_q2.size() == 1)
            {
                answer = max(abs(num_q2.front()), answer);
            }

            // q1과 q2의 포인터 교환
            num_q1.swap(num_q2);
            op_q1.swap(op_q2);
        }
    
    } while (next_permutation(op_order.begin(), op_order.end()));

    return answer;
}

int main()
{
    
    /*
    string expression = "100-200*300-500+20"; //60420
    */
    string expression = "50*6-3*2"; //300

    cout << solution(expression);

    return 0;
}