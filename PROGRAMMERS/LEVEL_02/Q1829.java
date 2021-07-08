package PROGRAMMERS.LEVEL_02;

import java.util.LinkedList;
import java.util.Queue;

public class Q1829 {

    public static void main(String[] args) {
        /*
            m	n
            6	4

            picture
            [[1, 1, 1, 0], [1, 2, 2, 0],
            [1, 0, 0, 1], [0, 0, 0, 1],
            [0, 0, 0, 3], [0, 0, 0, 3]]

            answer
            [4, 5]
         */
        int m = 6;
        int n = 4;
        int[][] picture =  {{1, 1, 1, 0},
                            {1, 2, 2, 0},
                            {1, 0, 0, 1},
                            {0, 0, 0, 1},
                            {0, 0, 0, 3},
                            {0, 0, 0, 3}};
        int[] res = solution(m, n, picture);
        for (int i : res) {
            System.out.println(i);
        }
    }
    public static class Pos {
        int x;
        int y;
        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static int[] dx = {0, 0, 1, -1};
    public static int[] dy = {1, -1, 0, 0};

    public static int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;

        boolean[][] visit = new boolean[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!(picture[i][j] == 0 || visit[i][j])) {
                    int size = getAreaSize(picture, visit, m, n, new Pos(i, j));

                    maxSizeOfOneArea = Math.max(maxSizeOfOneArea, size);
                    ++numberOfArea;
                }
            }
        }

        return new int[]{numberOfArea, maxSizeOfOneArea};
    }

    public static int getAreaSize(int[][] picture, boolean[][] visit, int M, int N, Pos start) {

        int size = 0;
        Queue<Pos> q = new LinkedList<>();
        q.add(start);
        visit[start.x][start.y] = true;

        while (!q.isEmpty()) {

            Pos now = q.poll();
            ++size;

            for (int i = 0; i < 4; ++i) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];

                if (nx < 0 || nx >= M || ny < 0 || ny >= N || visit[nx][ny]
                    || picture[start.x][start.y] != picture[nx][ny]) {
                    continue;
                }
                q.add(new Pos(nx, ny));
                visit[nx][ny] = true;
            }
        }

        return size;
    }
}
