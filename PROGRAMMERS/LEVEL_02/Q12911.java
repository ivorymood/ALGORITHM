// https://programmers.co.kr/learn/courses/30/lessons/12911
// 다음 큰 숫자
package PROGRAMMERS.LEVEL_02;

public class Q12911 {

    public static void main(String[] args) {
        /*
        n	result
        78	83
        15	23
         */
        int n = 78;
        System.out.println(solution(n));
    }

    public static int solution(int n) {

        int targetBitCnt = Integer.bitCount(n);
        int answer = n + 1;
        while (Integer.bitCount(answer) != targetBitCnt) {
            ++answer;
        }

        return answer;
    }
}
