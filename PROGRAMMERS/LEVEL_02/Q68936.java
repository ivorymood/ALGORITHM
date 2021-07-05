package PROGRAMMERS.LEVEL_02;

public class Q68936 {
    public static void main(String[] args) {
        /*
        arr	                                                        result
        [[1,1,0,0],[1,0,0,0],[1,0,0,1],[1,1,1,1]]	                [4,9]
        [[1,1,1,1,1,1,1,1],[0,1,1,1,1,1,1,1],[0,0,0,0,1,1,1,1],
        [0,1,0,0,1,1,1,1],[0,0,0,0,0,0,1,1],[0,0,0,0,0,0,0,1],
        [0,0,0,0,1,0,0,1],[0,0,0,0,1,1,1,1]]	                    [10,15]
         */

        int[][] arr = {{1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1}};
        int[] result = solution(arr);
        for (int num : result) {
            System.out.println(num);
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

    public static int[] solution(int[][] arr) {

        int N = arr.length;
        boolean[][] visit = new boolean[N][N];
        int[] ans = new int[2];

        dfs(arr, visit, new Pos(0, 0), N, ans);
        return ans;
    }

    public static boolean check(int[][] arr, Pos start, int N) {
        for (int i = start.x; i < start.x + N; ++i) {
            for (int j = start.y; j < start.y + N; ++j) {
                if (arr[start.x][start.y] != arr[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void dfs(int[][] arr, boolean[][] visit, Pos start, int N, int[] ans) {

        if (N == 1 || check(arr, start, N)) {
            int first = arr[start.x][start.y];
            ++ans[first];
            return;
        }

        int sx = start.x;
        int sy = start.y;
        int half = N / 2;
        dfs(arr, visit, new Pos(sx, sy), half, ans);
        dfs(arr, visit, new Pos(sx, sy + half), half, ans);
        dfs(arr, visit, new Pos(sx + half, sy), half, ans);
        dfs(arr, visit, new Pos(sx + half, sy + half), half, ans);
    }
}
