// https://www.acmicpc.net/problem/1786
#include <iostream>
#include <vector>

using namespace std;

// Prefix Index 배열 만들기
vector<int> make_pi(string &pattern)
{
    int len = pattern.size();
    vector<int> pi(len);

    for (int i = 1, j = 0; i < len; ++i)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = pi[j - 1];
        }

        if (pattern[i] == pattern[j])
        {
            pi[i] = ++j;
        }
    }
    return pi;
}

// kmp 알고리즘으로 parent에서 pattern이 등장하는 인덱스 배열 생성
vector<int> get_pattern_locations(string &parent, string &pattern)
{
    int str_len = parent.size();
    int pattern_len = pattern.size();
    vector<int> pi = make_pi(pattern);

    vector<int> locations;

    for (int i = 0, j = 0; i < str_len; ++i)
    {
        while (j > 0 && parent[i] != pattern[j])
        {
            j = pi[j - 1];
        }

        if (parent[i] == pattern[j])
        {
            ++j;

            // pattern이 모두 일치하면 처음 등장했던 idx를 locaitons에 push
            if (j == pattern_len)
            {
                locations.push_back(i - pattern_len + 1);
            }
        }
    }

    return locations;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    string parent, pattern;
    getline(cin, parent);
    getline(cin, pattern);

    // kmp 알고리즘으로 parent에서 pattern이 등장하는 인덱스 배열 생성
    vector<int> locations = get_pattern_locations(parent, pattern);

    // 출력
    cout << locations.size() << '\n';
    for (int location : locations)
    {
        cout << (location + 1) << ' ';
    }

    return 0;
}