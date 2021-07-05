package PROGRAMMERS.LEVEL_02;

import java.util.LinkedList;
import java.util.Queue;

public class Q1844 {

    public static void main(String[] args) {
        /*
        maps	                                                        answer
        [[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]	11
        [[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,0],[0,0,0,0,1]]	-1
         */

        int[][] maps = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};
        System.out.println(solution(maps));
    }

    public static class Pos {
        int x;
        int y;
        int dist;
        Pos (int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }

    public static int solution(int[][] maps) {

        int[] dx = new int[]{0, 0, 1, -1};
        int[] dy = new int[]{1, -1, 0, 0};
        int column = maps.length;
        int row = maps[0].length;

        boolean[][] visit = new boolean[column][row];
        visit[0][0] = true;
        Queue<Pos> q = new LinkedList<>();
        q.add(new Pos(0, 0, 1));

        while (!q.isEmpty()) {
            Pos p  = q.poll();

            if (p.x + 1 == column && p.y + 1 == row) {
                return p.dist;
            }

            for (int i = 0; i < 4; ++i) {

                int nx = p.x + dx[i];
                int ny = p.y + dy[i];

                if (nx < 0 || nx >= column || ny < 0 || ny >= row
                        || visit[nx][ny] || maps[nx][ny] != 1) {
                    continue;
                }
                q.add(new Pos(nx, ny, p.dist + 1));
                visit[nx][ny] = true;
            }
        }
        return -1;
    }
}
