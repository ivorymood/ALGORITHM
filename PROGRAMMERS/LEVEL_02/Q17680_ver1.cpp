//https://programmers.co.kr/learn/courses/30/lessons/17680
//ĳ��
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {

    const int HIT = 1;
    const int MISS = 5;

    // ĳ�� ����� 0 �ϰ��
    if (cacheSize == 0)
    {
        return cities.size() * MISS;
    }

    // <����ð�, ���ڿ�>�� ������ cache���� ����
    vector<pair<int, string>> cache(cacheSize);

    int time = 0;
    for (auto iter_city = cities.begin(); iter_city != cities.end(); ++iter_city)
    {
        // ã�� ���ڸ� �빮�ڷ� ��ȯ
        transform(iter_city->begin(), iter_city->end(), iter_city->begin(), ::toupper);

        // �� ���� ���� ������ ��ü�� ����ð��� 1�� ������
        for_each(cache.begin(), cache.end(), [](pair<int, string>& pr) {
            ++pr.first;
            });

        // cache���Ϳ��� �ش� ���� ã��
        auto iter_cache = find_if(cache.begin(), cache.end(), [&iter_city](const pair<int, string>& pr) ->bool {
            return pr.second.compare(*iter_city) == 0;
            });

        // cache���Ϳ��� ���ø� ã���� ��
        if (iter_cache != cache.end())
        {
            (*iter_cache).first = 0;

            time += HIT;
        }
        // cache���Ϳ� ���ð� ���� ��
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