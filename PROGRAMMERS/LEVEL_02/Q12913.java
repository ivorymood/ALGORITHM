// https://programmers.co.kr/learn/courses/30/lessons/12913?language=java
// 땅따먹기
package PROGRAMMERS.LEVEL_02;

public class Q12913 {

    public static void main(String[] args) {
        /*
        land	                            answer
        [[1,2,3,5],[5,6,7,8],[4,3,2,1]]	    16

         */
        int[][] land = {{1,2,3,5},{5,6,7,8},{4,3,2,1}};
        System.out.println(solution(land));
    }

    public static int solution(int[][] land) {

        int column = land[0].length;
        int row = land.length;

        for (int i = 1; i < row; ++i) {

            for (int j = 0; j < column; ++j) {

                // get max value of former row, except same column
                int tmpMax = 0;
                for (int k = 0; k < column; ++k) {
                    if (j == k) {
                        continue;
                    }
                    tmpMax = Math.max(tmpMax, land[i - 1][k]);
                }

                // memoize sum of current value and max value of former row
                land[i][j] += tmpMax;
            }
        }

        int answer = 0;
        for (int i = 0; i < column; ++i) {
            answer = Math.max(answer, land[row - 1][i]);
        }
        return answer;
    }
}
