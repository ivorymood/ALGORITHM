package PROGRAMMERS.LEVEL_02;

import java.util.ArrayList;
import java.util.List;

public class Q77485 {

    public static void main(String[] args) {
        /*
        rows	columns	queries	                                    result
        6	    6	    [[2,2,5,4],[3,3,6,6],[5,1,6,3]]	            [8, 10, 25]
        3	    3	    [[1,1,2,2],[1,2,2,3],[2,1,3,2],[2,2,3,3]]	[1, 1, 5, 3]
        100	    97	    [[1,1,100,97]]	                            [1]
         */
        int rows = 6;
        int columns = 6;
        int[][] queries = {{2,2,5,4}, {3,3,6,6}, {5,1,6,3}};
        List<Integer> result = solution(rows, columns, queries);
        for (int res : result) {
            System.out.println(res);
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

    public static List<Integer> solution(int rows, int columns, int[][] queries) {

        int[][] table = new int[rows + 1][columns + 1];
        for (int i = 1, num = 1; i <= rows; ++i) {
            for (int j = 1; j <= columns; ++j) {
                table[i][j] = num++;
            }
        }

        List<Integer> answer = new ArrayList<>();
        for (int[] query : queries) {

            Pos posLU = new Pos(query[0], query[1]);
            Pos posRD = new Pos(query[2], query[3]);
            answer.add(moveAndGetMin(table, posLU, posRD));
        }

        return answer;
    }

    public static int moveAndGetMin(int[][] table, Pos posLU, Pos posRD) {

        int tmp = table[posLU.x][posLU.y];
        int min = tmp;

        for (int x = posLU.x; x < posRD.x; ++x) {
            table[x][posLU.y] = table[x + 1][posLU.y];
            min = Math.min(min, table[x][posLU.y]);
        }
        for (int y = posLU.y; y < posRD.y; ++y) {
            table[posRD.x][y] = table[posRD.x][y + 1];
            min = Math.min(min, table[posRD.x][y]);
        }
        for (int x = posRD.x; x > posLU.x; --x) {
            table[x][posRD.y] = table[x - 1][posRD.y];
            min = Math.min(min, table[x][posRD.y]);
        }
        for (int y = posRD.y; y > posLU.y; --y) {
            table[posLU.x][y] = table[posLU.x][y - 1];
            min = Math.min(min, table[posLU.x][y]);
        }
        table[posLU.x][posLU.y + 1] = tmp;

        return min;
    }
}
