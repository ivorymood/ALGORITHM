package PROGRAMMERS.LEVEL_02;

public class Q17679 {

    public static void main(String[] args) {
        /*
        m	n	board	                                                        answer
        4	5	["CCBDE", "AAADE", "AAABF", "CCBBF"]	                        14
        6	6	["TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"]	15
        6   6   ["AABBEE", "AAAEEE", "VAAEEV", "AABBEE", "AACCEE", "VVCCEE"]    32
         */

        int m = 6;
        int n = 6;
        String[] board = {"AABBEE", "AAAEEE", "VAAEEV", "AABBEE", "AACCEE", "VVCCEE"};
        System.out.println(solution(m, n, board));
    }

    public static int solution(int m, int n, String[] board) {

        char[][] charBoard = new char[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                charBoard[i][j] = board[m - 1 - j].charAt(i);
            }
        }

        int sum = 0;
        int removedCnt = -1;
        while (removedCnt != 0) {

            boolean[][] square = new boolean[n][m];
            checkSquare(charBoard, square);
            removedCnt = remove(charBoard, square);
            move(charBoard, square);
            sum += removedCnt;
        }

        return sum;
    }

    public static boolean isAlpha(char c) {
        return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
    }

    public static void checkSquare(char[][] board, boolean[][] square) {

        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (isAlpha(board[i][j]) && isSquare(board, i, j)) {
                    square[i][j] = true;
                    square[i][j + 1] = true;
                    square[i + 1][j] = true;
                    square[i + 1][j + 1] = true;
                }
            }
        }
    }

    public static boolean isSquare(char[][] board, int y, int x) {
        if (y < 0 || y + 1 >= board.length || x < 0 || x + 1 >= board[0].length) {
            return false;
        }
        char c = board[y][x];
        return c == board[y][x + 1] && c == board[y + 1][x] && c == board[y + 1][x + 1];
    }

    public static int remove(char[][] board, boolean[][] square) {
        int cnt = 0;
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (square[i][j]) {
                    board[i][j] = ' ';
                    ++cnt;
                }
            }
        }
        return cnt;
    }

    public static void move(char[][] board, boolean[][] square) {

        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {

                if (!isAlpha(board[i][j])) {

                    int gap = 0;
                    for (int t = j + 1; t < board[0].length; ++t) {
                        if (isAlpha(board[i][t])) {
                            gap = t - j;
                            break;
                        }
                    }
                    if (gap == 0) {
                        break;
                    }

                    for (int k = j; k < board[0].length; ++k) {
                        board[i][k] = (k + gap < board[0].length) ? board[i][k + gap] : ' ';
                    }
                }
            }
        }
    }
}
