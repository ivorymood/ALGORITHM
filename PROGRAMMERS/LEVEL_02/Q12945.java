// https://programmers.co.kr/learn/courses/30/lessons/12945?language=java
// 피보나치 수
package PROGRAMMERS.LEVEL_02;

import java.util.Arrays;

public class Q12945 {

    public static void main(String[] args) {
        /*
        n	return
        3	2
        5	5
         */
        int n = 3;
        System.out.println(solution(n));
    }

    public static int solution(int n) {

        int[] memo = new int[n + 1];
        Arrays.fill(memo, -1);
        memo[0] = 0;
        memo[1] = 1;

        return fibonacci(n, memo);
    }

    public static int fibonacci(int n, int[] memo) {
        if (memo[n] >= 0) {
            return memo[n];
        }
        return memo[n] = (fibonacci(n - 1, memo) + fibonacci(n - 2, memo)) % 1234567;
    }
}
