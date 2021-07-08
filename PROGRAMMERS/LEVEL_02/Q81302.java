package PROGRAMMERS.LEVEL_02;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Q81302 {

    public static void main(String[] args) {
        /*
            places
            [["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"],
            ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"],
            ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"],
            ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"],
            ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]

            result
            [1, 0, 1, 1, 1]
         */
        String[][] places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                             {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                             {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                             {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                             {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};

        List<Integer> result = solution(places);
        for (int i : result) {
            System.out.println(i);
        }
    }

    public static final int LEN = 5;
    public static final char BLOCK = 'X';
    public static final char PERSON = 'P';
    public static final int[] dx = {0, 0, -1, 1};
    public static final int[] dy = {-1, 1, 0, 0};

    public static class Pos {
        int x;
        int y;
        int dist;
        Pos(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }

    public static List<Integer> solution(String[][] places) {

        List<Integer> answer = new ArrayList<>();
        for (String[] place : places) {
            answer.add(isOK(place) ? 1 : 0);
        }
        return answer;
    }

    public static boolean isOK(String[] place) {
        for (int i = 0; i < LEN; ++i) {
            for (int j = 0; j < LEN; ++j) {
                if (place[i].charAt(j) == PERSON) {
                    if (!isGoodDistance(place, new Pos(i, j, 0))) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    public static boolean isGoodDistance(String[] place, Pos start) {

        Queue<Pos> queue = new LinkedList<>();
        queue.add(start);
        boolean[][] visit = new boolean[LEN][LEN];
        visit[start.x][start.y] = true;

        while (!queue.isEmpty()) {

            Pos N = queue.poll();

            for (int i = 0; i < 4; ++i) {

                int nx = N.x + dx[i];
                int ny = N.y + dy[i];
                if (nx < 0 || nx >= LEN || ny < 0 || ny >= LEN || visit[nx][ny]
                    || N.dist + 1 > 2 || place[nx].charAt(ny) == BLOCK) {
                    continue;
                }

                if (place[nx].charAt(ny) == PERSON) {
                    return false;
                }

                queue.add(new Pos(nx, ny, N.dist + 1));
                visit[nx][ny] = true;
            }
        }
        return true;
    }
}
