//https://programmers.co.kr/learn/courses/30/lessons/67256
//Ű�е� ������
#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

struct pos {
    int x, y;
};

// 0 ~ 9 ������ ���� ��ġ �ű��
void set_pos(unordered_map<int, pos> &m)
{
    int key = 0;
    m[key++] = {3, 1};
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            m[key++] = {i, j};
        }
    }
}

string solution(vector<int> numbers, string hand) {

    // 0 ~ 9������ ���� ��ġ�� ����
    unordered_map<int, pos> pos_map;
    set_pos(pos_map);

    // �޼� ������ ���� ��ġ
    pos hand_L = { 3, 0 };
    pos hand_R = { 3, 2 };

    string answer = "";

    for (int i = 0; i < numbers.size(); ++i)
    {
        char c;
        int num = numbers[i];
        // �޼� ����
        if (num == 1 || num == 4 || num == 7)
        {
            hand_L = pos_map[num];
            c = 'L';
        }
        // ������ ����
        else if (num == 3 || num == 6 || num == 9)
        {
            hand_R = pos_map[num];
            c = 'R';
        }
        // ���
        else
        {
            // �� ���� ��ġ�� �޼�/������ ��ġ�� �Ÿ� ���ϱ�
            pos p_num = pos_map[num];
            int dist_R = abs(p_num.x - hand_R.x) + abs(p_num.y - hand_R.y);
            int dist_L = abs(p_num.x - hand_L.x) + abs(p_num.y - hand_L.y);

            // �޼��� �� �����ų� �޼�/������ �Ÿ��� ������ �޼������� ��
            if (dist_R > dist_L || (dist_L == dist_R && hand.compare("left") == 0))
            {
                hand_L = p_num;
                c = 'L';
            }
            // �������� �� �����ų� �޼�/������ �Ÿ��� ������ ������������ ��
            else if (dist_R < dist_L || (dist_L == dist_R && hand.compare("right") == 0))
            {
                hand_R = p_num;
                c = 'R';
            }
        }

        // ���� �����ֱ�
        answer += c;
    }

    return answer;
}

int main()
{
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }; string hand = "right";
    /*
    vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 }; string hand = "right";
    vector<int> numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 }; string hand = "left";
    */

    cout << solution(numbers, hand);

    return 0;
}