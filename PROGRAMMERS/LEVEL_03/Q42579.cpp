//https://programmers.co.kr/learn/courses/30/lessons/42579
//베스트앨범
#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct song{
    int num, play_cnt;
    string genre;
};

unordered_map<string, int> genre_cnts;

bool compare(song a, song b)
{
    // 1. 장르별 플레이 횟수 내림차순
    if (genre_cnts[a.genre] != genre_cnts[b.genre])
    {
        return genre_cnts[a.genre] > genre_cnts[b.genre];
    }
    // 2. 장르 내 재생 횟수 내림차순
    if (a.play_cnt != b.play_cnt)
    {
        return a.play_cnt > b.play_cnt;
    }
    // 3. 고유 번호 오름차순
    return a.num < b.num;
}

vector<int> solution(vector<string> genres, vector<int> plays) {

    /*
        genre_cnts맵에 장르별 플레이 횟수 카운트
        songs벡터에 노래 정보 저장
    */
    int N = genres.size();
    vector<song> songs(N);
    for (int i = 0; i < N; ++i)
    {
        genre_cnts[genres[i]] += plays[i];
        songs[i] = {i, plays[i], genres[i]};
    }

    // 문제 요구사항 순으로 정렬
    sort(songs.begin(), songs.end(), compare);

    // 장르별 노래 추출 횟수를 기록하기 위해 genre_cnts맵 초기화
    genre_cnts.clear();

    // 정렬된 순서대로 2개씩 노래 추출
    vector<int> answer;
    for (song s: songs)
    {
        if (genre_cnts[s.genre] < 2)
        {
            answer.push_back(s.num);
            ++genre_cnts[s.genre];
        }
    }
    return answer;
}

int main()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    vector<int> res =  solution(genres, plays);
    for (int i : res)
    {
        cout << i << ' ';
    }


    return 0;
}