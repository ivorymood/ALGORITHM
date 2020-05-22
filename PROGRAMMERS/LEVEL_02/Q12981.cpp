//https://programmers.co.kr/learn/courses/30/lessons/12981
// 영어 끝말잇기
#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    
    set<string> s;
    vector<int> answer(2);

    // 첫번째 단어 push
    s.insert(words[0]);

    // 2번째 단어부터 검사
    int len = words.size();
    for (int i = 1; i < len; ++i)
    {
        // 단어가 2번 이상 등장하거나, 앞 단어의 끝 글자와 같지 않다면
        if (s.find(words[i]) != s.end() || *words[i - 1].rbegin() != words[i][0])
        {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            return answer;
        }

        // 단어 push
        s.insert(words[i]);
    }

    return answer;
}

int main()
{
    /*
    int n = 3; vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
    int n = 5; vector<string> words = { "hello", "observe", "effect", "take", "either", 
                                    "recognize", "encourage", "ensure", "establish" , "hang" 
                                    "gather", "refer", "reference", "estimate" , "executive" };
    */
    int n = 2; vector<string> words = { "hello", "one", "even", "never", "now", "world", "draw" };

    vector<int> rtn = solution(n, words);
    for (int i : rtn)
    {
        cout << i << ", ";
    }

    return 0;
}