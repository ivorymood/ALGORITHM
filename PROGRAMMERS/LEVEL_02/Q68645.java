package PROGRAMMERS.LEVEL_02;

public class Q68645 {

    public static void main(String[] args) {
    /*
        n	result
        4	[1,2,9,3,10,8,4,5,6,7]
        5	[1,2,12,3,13,11,4,14,15,10,5,6,7,8,9]
        6	[1,2,15,3,16,14,4,17,21,13,5,18,19,20,12,6,7,8,9,10,11]
     */

        int n = 4;
        int[] result = solution(n);
        for (int i : result) {
            System.out.println(i);
        }
    }

    public static int[] solution(int n) {

        int[][] triangle = new int[n][n];
        int x = -1;
        int y = 0;
        int number = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (i % 3 == 0) {
                    ++x;
                } else if (i % 3 == 1) {
                    ++y;
                } else if (i % 3 == 2){
                    --x;
                    --y;
                }
                triangle[x][y] = number++;
            }
        }

        int idx = 0;
        int[] answer = new int[n * (n + 1) / 2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                answer[idx++] = triangle[i][j];
            }
        }

        return answer;
    }
}
