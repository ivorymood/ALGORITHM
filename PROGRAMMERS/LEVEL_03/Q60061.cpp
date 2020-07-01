//https://programmers.co.kr/learn/courses/30/lessons/60061
//기둥과 보 설치
#include <iostream>

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

enum {PILLAR, BEAM};

// 설치물 전체의 정합성 체크
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
                현재 위치가 바닥이거나 왼쪽에 기둥이 있거나 
                위쪽에 보가 있거나 같은 위치에 보가 있어야 true
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
                왼쪽에 기둥이 있거나 왼,아래쪽에 기둥이 있거나 
                위아래에 보가 있어야 true
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
        
        // 설치할 때
        if (work == 1)
        {
            s.insert({x, y, type });
            
            // 정합성이 맞지 않으면 다시 지우기
            if (!check(s))
            {
                s.erase({x, y, type});
            }
        }
        // 철거할 때
        else 
        {
            s.erase({ x, y, type });

            // 정합성이 맞지 않으면 다시 설치하기
            if (!check(s))
            {
                s.insert({ x, y, type });
            }
        }
    }

    /*
        set -> vector 옮겨주기
        set이 오름차순을 유지하기 때문에 정렬은 필요X
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