//https://programmers.co.kr/learn/courses/30/lessons/42579
//����Ʈ�ٹ�
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
    // 1. �帣�� �÷��� Ƚ�� ��������
    if (genre_cnts[a.genre] != genre_cnts[b.genre])
    {
        return genre_cnts[a.genre] > genre_cnts[b.genre];
    }
    // 2. �帣 �� ��� Ƚ�� ��������
    if (a.play_cnt != b.play_cnt)
    {
        return a.play_cnt > b.play_cnt;
    }
    // 3. ���� ��ȣ ��������
    return a.num < b.num;
}

vector<int> solution(vector<string> genres, vector<int> plays) {

    /*
        genre_cnts�ʿ� �帣�� �÷��� Ƚ�� ī��Ʈ
        songs���Ϳ� �뷡 ���� ����
    */
    int N = genres.size();
    vector<song> songs(N);
    for (int i = 0; i < N; ++i)
    {
        genre_cnts[genres[i]] += plays[i];
        songs[i] = {i, plays[i], genres[i]};
    }

    // ���� �䱸���� ������ ����
    sort(songs.begin(), songs.end(), compare);

    // �帣�� �뷡 ���� Ƚ���� ����ϱ� ���� genre_cnts�� �ʱ�ȭ
    genre_cnts.clear();

    // ���ĵ� ������� 2���� �뷡 ����
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