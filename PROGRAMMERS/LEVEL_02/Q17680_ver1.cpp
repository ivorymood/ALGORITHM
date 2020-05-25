//https://programmers.co.kr/learn/courses/30/lessons/17680
//캐시
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {

    const int HIT = 1;
    const int MISS = 5;

    // 캐시 사이즈가 0 일경우
    if (cacheSize == 0)
    {
        return cities.size() * MISS;
    }

    // <경과시간, 문자열>을 저장할 cache벡터 선언
    vector<pair<int, string>> cache(cacheSize);

    int time = 0;
    for (auto iter_city = cities.begin(); iter_city != cities.end(); ++iter_city)
    {
        // 찾을 문자를 대문자로 변환
        transform(iter_city->begin(), iter_city->end(), iter_city->begin(), ::toupper);

        // 한 텀이 지날 때마다 전체에 경과시간을 1씩 더해줌
        for_each(cache.begin(), cache.end(), [](pair<int, string>& pr) {
            ++pr.first;
            });

        // cache벡터에서 해당 도시 찾기
        auto iter_cache = find_if(cache.begin(), cache.end(), [&iter_city](const pair<int, string>& pr) ->bool {
            return pr.second.compare(*iter_city) == 0;
            });

        // cache벡터에서 도시를 찾았을 때
        if (iter_cache != cache.end())
        {
            (*iter_cache).first = 0;

            time += HIT;
        }
        // cache벡터에 도시가 없을 때
        else
        {
            auto lru_iter = max_element(cache.begin(), cache.end());
            (*lru_iter).first = 0;
            (*lru_iter).second = *iter_city;

            time += MISS;
        }
    }

    return time;
}

int main()
{
    /*
    int cacheSize = 3; vector<string> cities = { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" };
    int cacheSize = 3; vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
    int cacheSize = 2; vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
    int cacheSize = 0; vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
    int cacheSize = 2; vector<string> cities = { "Jeju", "Pangyo", "NewYork", "NewYork"};
    */
    int cacheSize = 5; vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };

    cout << solution(cacheSize, cities);

    return 0;
}