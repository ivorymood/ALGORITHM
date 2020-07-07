//https://programmers.co.kr/learn/courses/30/lessons/67257
//���� �ִ�ȭ
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
        // ���� ���ڰ� ������ ��
        if (exp[i] >= '0')
        {
            num *= 10;
            num += exp[i] - '0';
        }
        // ���� ���ڰ� �������� ��
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

    // ���� �迭�� ������ �迭 �����
    vector<long long> nums;
    vector<char> ops;
    classify_nums_ops(expression, nums, ops);

    // 3�� �������� ������ ���� ���ڿ� ���� �� ����
    string op_order = "+-*";
    sort(op_order.begin(), op_order.end());


    long long answer = 0;
    do 
    {
        /*
            ���ڿ��� �����ڿ��� q1�� ����.
            q2�� 1���� ��� ���� ���ڿ��� �����ڿ��� ����� ť
        */
        queue<long long, deque<long long>> num_q2, num_q1(deque<long long>(nums.begin(), nums.end()));
        queue<char, deque<char>> op_q2, op_q1(deque<char>(ops.begin(), ops.end()));

        for (int i = 0; i < 3; ++i)
        {
            // last : �߰��� ���� ���ڸ� ����
            long long last = num_q1.front();
            num_q1.pop();

            while (!op_q1.empty())
            {
                // �ش���� �������� �� : ���� ������ ���� last�� ����
                if (op_q1.front() == op_order[i])
                {
                    last = cal(last, num_q1.front(), op_q1.front());
                }
                // �ش���� �����ڰ� �ƴ� �� : last�� q2�� ���� ��, q1�� ���� ���ڷ� ��ü
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

            // �������� ���� ����ť�� ���Ұ� 1���� �� : �ִ� ���밪 ����
            if (num_q2.size() == 1)
            {
                answer = max(abs(num_q2.front()), answer);
            }

            // q1�� q2�� ������ ��ȯ
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