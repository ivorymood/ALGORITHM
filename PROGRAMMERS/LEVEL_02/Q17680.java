package PROGRAMMERS.LEVEL_02;

import java.util.LinkedList;
import java.util.Queue;

public class Q17680 {

    public static void main(String[] args) {
        /*
        도시이름(cities)	                                        캐시크기(cacheSize)	실행시간
        ["Jeju", "Pangyo", "Seoul", "NewYork", "LA",
            "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]	        3                   50
        ["Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo",
            "Seoul", "Jeju", "Pangyo", "Seoul"]	                3                   21
        ["Jeju", "Pangyo", "Seoul", "NewYork", "LA",
            "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju",
            "NewYork", "Rome"]	                                2                   60
        ["Jeju", "Pangyo", "Seoul", "NewYork", "LA",
            "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju",
            "NewYork", "Rome"]	                                5                   52
        ["Jeju", "Pangyo", "NewYork", "newyork"]	            2                   16
        ["Jeju", "Pangyo", "Seoul", "NewYork", "LA"]	        0                   25
         */

        String[] cities = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
        int cacheSize = 3;
        System.out.println(solution(cacheSize, cities));
    }

    public static int solution(int cacheSize, String[] cities) {

        final int HIT = 1;
        final int MISS = 5;
        if (cacheSize == 0) {
            return cities.length * MISS;
        }

        int time = 0;
        Queue<String> queue = new LinkedList<>();

        for (String city : cities) {
            city = city.toUpperCase();

            if (queue.remove(city)) {

                time += HIT;
            } else {

                time += MISS;
                if (queue.size() == cacheSize) {
                    queue.poll();
                }
            }
            queue.add(city);
        }

        return time;
    }
}
