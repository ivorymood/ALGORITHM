// https://programmers.co.kr/learn/courses/30/lessons/12985?language=java
// 예상 대진표
package PROGRAMMERS.LEVEL_02;

public class Q12985 {
    public static void main(String[] args) {
        /*
        N	A	B	answer
        8	4	7	3

         */

        int n = 8;
        int a = 4;
        int b = 7;
        System.out.println(solution(n, a, b));
    }

    public static int solution(int n, int a, int b) {

        return Integer.toBinaryString((a - 1) ^ (b - 1)).length();
    }
}
