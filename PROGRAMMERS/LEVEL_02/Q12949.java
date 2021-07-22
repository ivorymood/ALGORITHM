// https://programmers.co.kr/learn/courses/30/lessons/12949?language=java
// 행렬의 곱셈
package PROGRAMMERS.LEVEL_02;

public class Q12949 {

    public static void main(String[] args) {
        /*
        arr1	                            arr2	                            return
        [[1, 4], [3, 2], [4, 1]]	        [[3, 3], [3, 3]]	                [[15, 15], [15, 15], [15, 15]]
        [[2, 3, 2], [4, 2, 4], [3, 1, 4]]	[[5, 4, 3], [2, 4, 1], [3, 1, 1]]	[[22, 22, 11], [36, 28, 18], [29, 20, 14]]
         */

        int[][] arr1 = {{1, 4}, {3, 2}, {4, 1}};
        int[][] arr2 = {{3, 3}, {3, 3}};
        int[][] res = solution(arr1, arr2);
        for (int[] arr : res) {
            for (int i : arr) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }


    public static int[][] solution(int[][] arr1, int[][] arr2) {

        int column = arr1.length;
        int row = arr2[0].length;
        int cor = arr1[0].length;
        int[][] answer = new int[column][row];

        for (int i = 0; i < column; ++i) {
            for (int j = 0; j < row; ++j) {
                for (int k = 0; k < cor; ++k) {
                    answer[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        return answer;
    }
}
