// https://programmers.co.kr/learn/courses/30/lessons/12905?language=java
// 가장 큰 정사각형 찾기

package PROGRAMMERS.LEVEL_02;

public class Q12905 {
    public static void main(String[] args) {
        /*
        board	                                    answer
        [[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]]	9
        [[0,0,1,1],[1,1,1,1]]	                    4

         */
        int [][]board = {{0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0}};
        System.out.println(solution(board));
    }

    public final static int SQURE = 1;
    public static int solution(int [][]board) {

        int maxLen = 0;
        for (int y = 0; y < board.length; ++y) {
            for (int x = 0; x < board[0].length; ++x) {
                if (board[y][x] == SQURE) {
                    if (!(y == 0 || x == 0)) {
                        board[y][x] = Math.min(board[y][x - 1],
                                        Math.min(board[y - 1][x], board[y - 1][x - 1])) + 1;
                    }
                    maxLen = Math.max(maxLen, board[y][x]);
                }
            }
        }
        return maxLen * maxLen;
    }
}
