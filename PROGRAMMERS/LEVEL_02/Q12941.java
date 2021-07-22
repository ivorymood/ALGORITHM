// https://programmers.co.kr/learn/courses/30/lessons/12941?language=java
// 최솟값 만들기
package PROGRAMMERS.LEVEL_02;

import java.util.Arrays;

public class Q12941 {

    public static void main(String[] args) {
        /*
        A	        B	        answer
        [1, 4, 2]	[5, 4, 4]	29
        [1,2]	    [3,4]	    10
         */
        int[] A = {1, 4, 2};
        int[] B = {5, 4, 4};
        System.out.println(solution(A, B));
    }

    public static int solution(int []A, int []B) {

        Arrays.sort(A);
        Arrays.sort(B);

        int sum = 0;
        int len = A.length;
        for (int i = 0; i < len; ++i) {
            sum += A[i] * B[len - 1 - i];
        }
        return sum;
    }
}
