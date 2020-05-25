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

    // ĳ�ø� ������ ����, �ð� ����� ������ ���� ����
    vector<string> q(cacheSize);

    int time = 0;
    for (auto iter_city = cities.begin(); iter_city != cities.end(); ++iter_city)
    {
        // ���ڸ� �빮�ڷ� ��ȯ
        transform(iter_city->begin(), iter_city->end(), iter_city->begin(), ::toupper);

        // cache���Ϳ��� �ش� ���� ã��
        auto iter_cache = find_if(q.begin(), q.end(), [&iter_city](const string& s) ->bool {
            return s.compare(*iter_city) == 0;
            });
        
        // cache���Ϳ��� ���ø� ã���� ��
        if (iter_cache != q.end())
        {
            q.erase(iter_cache);
            q.push_back(*iter_city);

            time += HIT;
        }
        // cache���Ϳ� ���ð� ���� ��
        else
        {
            if (q.size() >= cacheSize)
            {
                q.erase(q.begin());
            }
            if (q.size() < cacheSize)
            {
                q.push_back(*iter_city);
            }

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