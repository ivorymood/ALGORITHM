//https://programmers.co.kr/learn/courses/30/lessons/60061
//��հ� �� ��ġ
#include <iostream>

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

enum {PILLAR, BEAM};

// ��ġ�� ��ü�� ���ռ� üũ
bool check(const set<vector<int>> &s)
{
    for (const vector<int> &v : s)
    {
        int x = v[0];
        int y = v[1];
        int type = v[2];

        if (type == PILLAR)
        {
            /*
                ���� ��ġ�� �ٴ��̰ų� ���ʿ� ����� �ְų� 
                ���ʿ� ���� �ְų� ���� ��ġ�� ���� �־�� true
            */
            if ( !(y == 0 || s.count({x, y - 1, PILLAR })
                || s.count({ x - 1, y, BEAM }) || s.count({ x, y, BEAM })) )
            {
                return false;
            }
        }
        else 
        {
            /*
                ���ʿ� ����� �ְų� ��,�Ʒ��ʿ� ����� �ְų� 
                ���Ʒ��� ���� �־�� true
            */
            if ( !(s.count({x, y - 1, PILLAR}) || s.count({ x + 1, y - 1, PILLAR })
                || ( s.count({ x - 1, y, BEAM }) && s.count({ x + 1, y, BEAM }) ) ) )
            {
                return false;
            }
        }
    }
   
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {

    set<vector<int>> s;

    for (vector<int> &v : build_frame)
    {
        int x = v[0];
        int y = v[1];
        int type = v[2];
        int work = v[3];
        
        // ��ġ�� ��
        if (work == 1)
        {
            s.insert({x, y, type });
            
            // ���ռ��� ���� ������ �ٽ� �����
            if (!check(s))
            {
                s.erase({x, y, type});
            }
        }
        // ö���� ��
        else 
        {
            s.erase({ x, y, type });

            // ���ռ��� ���� ������ �ٽ� ��ġ�ϱ�
            if (!check(s))
            {
                s.insert({ x, y, type });
            }
        }
    }

    /*
        set -> vector �Ű��ֱ�
        set�� ���������� �����ϱ� ������ ������ �ʿ�X
    */
    vector<vector<int>> answer;
    copy(s.begin(), s.end(), back_inserter(answer));

    return answer;
}

int main()
{

    int n = 5; vector<vector<int>> build_frame = {{0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1}};
    /*
    int n = 5; vector<vector<int>> build_frame = {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}};
    */

    vector<vector<int>> res = solution(n, build_frame);
    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[0].size(); ++j)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}