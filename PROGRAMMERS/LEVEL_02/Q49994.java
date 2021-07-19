// https://programmers.co.kr/learn/courses/30/lessons/49994?language=java
// 방문 길이
package PROGRAMMERS.LEVEL_02;

import java.util.*;

public class Q49994 {

    public static void main(String[] args) {
        /*
        dirs	    answer
        "ULURRDLLU"	7
        "LULLLLLLU"	7
         */
        String dirs = "ULURRDLLU";
        System.out.println(solution(dirs));
    }

    public static class Pos{
        int y, x;
        Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public boolean equals(Object o) {
            Pos pos = (Pos) o;
            return y == pos.y && x == pos.x;
        }

        @Override
        public int hashCode() {
            return Objects.hash(y, x);
        }
    }

    public static class Road{
        Pos start, end;
        Road(Pos start, Pos end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public boolean equals(Object o) {
            Road road = (Road) o;
            return start.equals(road.start) && end.equals(road.end);
        }

        @Override
        public int hashCode() {
            return Objects.hash(start, end);
        }
    }

    public static int solution(String dirs) {

        Map<Character, int[]> dirMap = new HashMap<>();
        dirMap.put('U', new int[] {1, 0});
        dirMap.put('D', new int[] {-1, 0});
        dirMap.put('R', new int[] {0, 1});
        dirMap.put('L', new int[] {0, -1});

        Set<Road> set = new HashSet<>();
        int[][] map = new int[11][11];
        Pos now = new Pos(5, 5);

        for (char c : dirs.toCharArray()) {

            Pos next = new Pos(now.y + dirMap.get(c)[0], now.x + dirMap.get(c)[1]);
            if (next.y < 0 || next.y >= map.length || next.x < 0 || next.x >= map[0].length) {
                continue;
            }

            Road road = new Road(now, next);
            if (!set.contains(road)) {
                set.add(road);
                set.add(new Road(next, now));
            }
            now = next;
        }

        return set.size() / 2;
    }
}
