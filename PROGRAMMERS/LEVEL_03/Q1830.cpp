//https://programmers.co.kr/learn/courses/30/lessons/1830
//����̾��� ���
#include <iostream>

#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> group;
vector<bool> rule_1;
vector<bool> rule_2;
vector<bool> used;
int w_idx;

struct info 
{
    int start, end, cnt;
};

bool check_rule_1(string& sentence, info l_info, char c)
{
    // ��������� �ִ� �ҹ����̸� X
    if (used[c - 'a'] == true)
    {
        return false;
    }
    // �ҹ��ڵ��� �� ��/�ڿ��� ��ĭ�� �� ���ư� �ڸ��� sentence�� ������ ������ X
    if (l_info.start - 1 < 0 || l_info.end + 1 >= N)
    {
        return false;
    }
    // �ҹ��ڵ��� �� ��/�ڿ��� ��ĭ�� �� ���ư� �ڸ��� ���ڰ� �빮�ڰ� �ƴϸ� X
    if (islower(sentence[l_info.start - 1]) || islower(sentence[l_info.end + 1]))
    {
        return false;
    }

    int l_cnt = 0, u_cnt = 0;
    for (int i = l_info.start - 1; i <= l_info.end + 1; ++i)
    {
        char now = sentence[i];
        if (islower(now))
        {
            // ���� ��Ģüũ���� �ҹ����̸�: �׷� �ε���
            if (now == c)
            {
                group[i] = w_idx;
                ++l_cnt;
                u_cnt = 0;
            }
            // 1����Ģ üũ���ε� �߰��� �ٸ����ڰ� ������ X
            else
            {
                return false;
            }
        }
        else if (isupper(now))
        {
            l_cnt = 0;
            ++u_cnt;

            // �̹� ���� ��Ģ�� ����Ǿ� ������ X
            if (rule_1[i] == true)
            {
                return false;
            }
            // ���� ��Ģ�� ������� ������ �׷� �ε���, ��Ģ���� üũ
            else 
            {
                group[i] = w_idx;
                rule_1[i] = true;
            }
        }
        
        // ���� �ҹ��� �Ǵ� (���ų� �ٸ�)�빮�ڰ� �������� �ִ� ���
        if (l_cnt > 1 || u_cnt > 1)
        {
            return false;
        }
    }

    // �ܾ� �ε��� ���� & �ҹ��� ��� üũ
    ++w_idx;
    used[c - 'a'] = true;
    return true;
}

bool check_rule_2(string& sentence, info l_info, char c)
{
    // ��������� �ִ� �ҹ����̸� X
    if (used[c - 'a'] == true)
    {
        return false;
    }
    // �ش� �ҹ��ڳ����� �Ÿ��� 2 �̸��̸� X
    if (l_info.end - l_info.start < 2)
    {
        return false;
    }

    // 2�� ��Ģ�� �յ� �ҹ��� �׷� �ε���
    group[l_info.start] = w_idx;
    group[l_info.end] = w_idx;

    // �Ǿ�, �ǵ� �ҹ��� ������ ���ڵ��� �˻�
    for (int i = l_info.start + 1; i < l_info.end; ++i)
    {
        char now = sentence[i];
        
        if (isupper(now))
        {
            // �̹� ���� ��Ģ�� ����Ǿ� ������ X
            if (rule_2[i] == true)
            {
                return false;
            }
            // ���� ��Ģ�� ������� ������ �׷� �ε���, ��Ģ���� üũ
            else 
            {
                group[i] = w_idx;
                rule_2[i] = true;
            }
        }
    }

    // �ܾ� �ε��� ���� & �ҹ��� ��� üũ
    ++w_idx;
    used[c - 'a'] = true;
    return true;
}

// ���� ���ڵ��� �� ��/�� �ε����� ���� ���� ����ü�� ��ȯ
info get_char_info(string& sentence, char c)
{
    int start = -1;
    int cnt = 0;
    int end = 0;
    for (int i = 0; i < N; ++i)
    {
        if (sentence[i] == c)
        {
            if (start < 0)
            {
                start = i;
            }
            ++cnt;
            end = i;
        }
    }
    return {start, end, cnt};
}

bool decrypting_possible(string &sentence)
{
    vector<bool> check_chars(26);
    for (int i = 0; i < N; ++i)
    {
        char now = sentence[i];

        // ��ȣȭ�� ���ڴ� ��ĭ�� ������ �ȵ�
        if (now == ' ')
        {
            return false;
        }

        // ���� üũ���� ���� ���ڶ��
        if (group[i] == 0)
        {
            // ���� ���ڰ� �빮��
            if (isupper(now))
            {
                // ������ �����϶�: ���� ���ڸ� ������ �ܾ� ���
                if (i + 1 >= N)
                {
                    group[i] = w_idx++;
                    continue;
                }

                char next = sentence[i + 1];
                
                // ���� ���ڰ� �빮���϶�: ���� ���ڸ� ������ �ܾ� ���
                if (isupper(next))
                {
                    group[i] = w_idx++;
                }
                // ���� ���ڰ� �ҹ����϶�
                else if (islower(next))
                {
                    // ���� ����(�ҹ���)�� ����/�� �ε���, ���� ���� �޾ƿ���
                    info l_info = get_char_info(sentence, next);

                    // ���� ����(�ҹ���) ������ 2���̸�: ���繮�ڸ� ������ �ܾ�� ���
                    if (l_info.cnt == 2)
                    {
                        group[i] = w_idx++;
                    }
                    /*
                        ���� ����(�ҹ���) ������ 2���� �ƴϸ�
                        : ���� ���ڸ� �����ϴ� �ܾ ��Ģ 1�� �������� Ȯ��
                    */
                    else
                    {
                        if (check_rule_1(sentence, l_info, next) == false)
                        {
                            return false;
                        }
                    }
                }
            }
            // ���� ���ڰ� �ҹ���
            else if (islower(now))
            {
                // ���� ����(�ҹ���)�� ����/�� �ε���, ���� ���� �޾ƿ���
                info l_info = get_char_info(sentence, now);

                // ����(�ҹ���) ������ 2���̸�
                if (l_info.cnt == 2)
                {
                    /*
                        ���� ���ڰ� �빮���̰�, ��Ģ 2���� �̹� ����� ���¶��
                        : ���� ���ڸ� �����ϴ� �ܾ ��Ģ 1�� �������� Ȯ��
                    */
                    if (isupper(sentence[i + 1]) && rule_2[i + 1])
                    {
                        if (check_rule_1(sentence, l_info, now) == false)
                        {
                            return false;
                        }
                    }
                    /*
                        �׷��� ������
                        : ���� ���ڸ� �����ϴ� �ܾ ��Ģ 2�� �������� Ȯ��
                    */
                    else 
                    {
                        if (check_rule_2(sentence, l_info, now) == false)
                        {
                            return false;
                        }
                    }
                }
                // ����(�ҹ���) ������ 2���� �ƴϸ�
                else
                {
                    // ���� ���ڸ� �����ϴ� �ܾ ��Ģ 1�� �������� Ȯ��
                    if (check_rule_1(sentence, l_info, now) == false)
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

string make_answer(string &sentence)
{
    // last_idx : ù��° �빮�� �ε����� ����
    int last_idx = 0;
    for (int i = 0; i < N; ++i)
    {
        if (isupper(sentence[i]))
        {
            last_idx = group[i];
            break;
        }
    }

    // �ε����� ���� �ٸ� ���ڴ� �ٸ� �ܾ�� ����Ͽ� �ڿ� ' ' ����
    string answer = "";
    for (int i = 0; i < N; ++i)
    {
        char c = sentence[i];
        if (isupper(c))
        {
            if (group[i] != last_idx)
            {
                answer += ' ';
            }

            answer += c;
            last_idx = group[i];
        }
    }
    return answer;
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
string solution(string sentence) {

    N = sentence.size();
    group = vector<int>(N);
    rule_1 = vector<bool>(N);
    rule_2 = vector<bool>(N);
    used = vector<bool>(26);
    w_idx = 1;


    // ������ �� �ִ� ���ڿ����� �˻�
    bool result = decrypting_possible(sentence);

    // �����Ҽ� ���� ���ڿ��̸� invalid��ȯ
    if (!result)
    {
        return "invalid";
    }

    return make_answer(sentence);
}

int main()
{
    vector<string> testcase;
    testcase.push_back("HaEaLaLaObWORLDb"); //HELLO WORLD
    testcase.push_back("SpIpGpOpNpGJqOqA"); //SIGONG JOA
    testcase.push_back("A"); //A
    testcase.push_back("HELLOWORLD"); //HELLOWORLD
    testcase.push_back("aHbEbLbLbOacWdOdRdLdDc"); //HELLO WORLD
    testcase.push_back("HaEaLaLObWORLDb"); //HELL O WORLD
    testcase.push_back("AAA"); //AAA
    testcase.push_back("aHELLOWORLDa"); //HELLOWORLD
    testcase.push_back("AAAaBaAbBBBBbCcBdBdBdBcCeBfBeGgGGjGjGRvRvRvRvRvR"); //AA ABA BBBB C BBBB C BB GG GGG RRRRRR
    testcase.push_back("aIaAM"); //I AM
    testcase.push_back("bAaOb"); //AO
    testcase.push_back("AxAxAxAoBoBoB"); //invalid
    testcase.push_back("a"); //invalid
    testcase.push_back("Aa"); //invalid
    testcase.push_back("aA"); //invalid
    testcase.push_back("HaEaLaLaOWaOaRaLaD"); //invalid
    testcase.push_back("abHELLObaWORLD"); //invalid
    testcase.push_back("aHELLOa bWORLDb"); //invalid
    testcase.push_back("TxTxTxbAb"); //invalid
    testcase.push_back("bTxTxTaTxTbkABaCDk"); //invalid
    testcase.push_back("baHELLOabWORLD"); //invalid
    testcase.push_back("AxAxAxABcBcBcB"); //AAAA BBBB
    testcase.push_back("A B"); //invalid
    testcase.push_back("oBBoA"); //BB A
    testcase.push_back("AxAxAxA"); //AAAA
    testcase.push_back("HaEaLaLaObWORLDbSpIpGpOpNpGJqOqAdGcWcFcDdeGfWfLeoBBoAAAAxAxAxAA");
    //HELLO WORLD SIGONG J O A GWFD GWL BB AAA AAAA A
    testcase.push_back("aBcAadDeEdvAvlElmEEEEm"); //BA DE A E EEEE
    testcase.push_back("AcAcABaBaB"); //A A AB B B
    testcase.push_back("aGbWbFbDakGnWnLk"); //GWFD GWL
    testcase.push_back("aCaCa"); //invalid

    for (int i = 0; i < testcase.size(); ++i)
    {
        cout << '[' << solution(testcase[i]) << ']' << '\n';
    }

    return 0;
}