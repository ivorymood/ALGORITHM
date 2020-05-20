//https://programmers.co.kr/learn/courses/30/lessons/12949
//행렬의 곱셈
#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    
    int Arow = arr1.size();
    int Acol = arr1[0].size(); // Acol == Brow
    int Bcol = arr2[0].size();

    // 행렬(a * k) * 행렬(k * b) --> 행렬(a * b)
    vector<vector<int>> answer(Arow, vector<int>(Bcol));
    for (int i = 0; i < Arow; ++i)
    {
        for (int j = 0; j < Bcol; ++j)
        {
            for (int k = 0; k < Acol; ++k)
            {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return answer;
}

int main()
{
    /*
    vector<vector<int>> arr1 = { {1, 4} ,{3, 2} ,{4, 1} };
    vector<vector<int>> arr2 = { {3, 3} ,{3, 3} };
    */
    vector<vector<int>> arr1 = { {2, 3, 2} ,{4, 2, 4} ,{3, 1, 4} };
    vector<vector<int>> arr2 = { {5, 4, 3} ,{2, 4, 1} ,{3, 1, 1} };

    vector<vector<int>> answer = solution(arr1, arr2);
    for (vector<int> v : answer)
    {
        for (int i : v)
        {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}