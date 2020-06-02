//https://programmers.co.kr/learn/courses/30/lessons/42895
//N���� ǥ��
#include <iostream>

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAX = 8;

// aim�� ����� N�� �ּ� ������ ��ȯ
int go(vector<unordered_set<int>>& v_set, int cnt, int aim)
{
    // ������ 8 �ʰ��̸� -1 ��ȯ
    if (cnt > MAX)
    {
        return -1;
    }

    /*
        �� ���ڸ� �̷�� N�� ������ cnt���� set���� ���ڷ� ��Ģ���� ��
        ������� ���ڸ� v_set[cnt]�� insert
        
        ex) cnt = 3 �϶�, v_set[1]�� ���ڵ� ~ v_set[2]�� ���ڵ� ���� ����� v_set[3]�� insert
                          v_set[2]�� ���ڵ� ~ v_set[1]�� ���ڵ� ���� ����� v_set[3]�� insert
    */
    for (int i = 1; i < cnt; ++i)
    {
        for (int num1 : v_set[i])
        {
            for (int num2 : v_set[cnt - i])
            {
                v_set[cnt].insert(num1 + num2);
                v_set[cnt].insert(num1 - num2);
                v_set[cnt].insert(num1 * num2);

                if (num2 != 0)
                {
                    v_set[cnt].insert(num1 / num2);
                }
            }
        }
    }

    // v_set[cnt]���� ��ǥ�� ���ڸ� ã���� cnt��ȯ (= �ּ� ����)
    if (v_set[cnt].find(aim) != v_set[cnt].end())
    {
        return cnt;
    }

    // ã�� ���ߴٸ� cnt + 1�� go�Լ� ���ȣ��
    return go(v_set, cnt + 1, aim);
}

int solution(int N, int number) {
   
    // v_set[cnt] : N�� cnt�� ����� ���ڵ��� set
    vector<unordered_set<int>> v_set(MAX + 1);
    
    /*
        ���� N, NN, NNN ... NNNNNNNN�� �̸� �� ���տ� �־���.
        
        ex) N�� v_set[1]��, NNN�� v_set[3]�� insert
    */
    int base = 0;
    for (int i = 1; i <= MAX; ++i)
    {
        base = base * 10 + N;
        v_set[i].insert(base);
    }

    // number�� ����� N�� �ּ� ������ ��ȯ. ������ 8 �ʰ��̸� -1 ��ȯ
    return go(v_set, 2, number);
}

int main()
{
    /*
    int N = 5; int number = 12; 
    int N = 5; int number = 31168;
    */
    int N = 2; int number = 11;

    cout << solution(N, number);

    return 0;
}