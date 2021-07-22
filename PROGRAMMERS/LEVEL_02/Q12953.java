// https://programmers.co.kr/learn/courses/30/lessons/12953?language=java
// N개의 최소공배수
package PROGRAMMERS.LEVEL_02;

public class Q12953 {
    public static void main(String[] args) {
        /*
        arr	        result
        [2,6,8,14]	168
        [1,2,3]	    6
         */

        int[] arr = {1, 2, 3};
        System.out.println(solution(arr));
    }

    public static int solution(int[] arr) {

        int lcm = arr[0];
        for (int i = 1; i < arr.length; ++i) {
            int gcd = GCD(lcm, arr[i]);
            lcm *= arr[i] / gcd;
        }

        return lcm;
    }

    public static int GCD(int A, int B) {
        if (B == 0) {
            return A;
        }
        return GCD(B, A % B);
    }
}
