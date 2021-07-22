// https://programmers.co.kr/learn/courses/30/lessons/12924
// 숫자의 표현
package PROGRAMMERS.LEVEL_02;

public class Q12924 {

    public static void main(String[] args) {
        /*
        n	result
        15	4
         */
        int n = 15;
        System.out.println(solution(n));
    }

    public static int solution(int n) {

        int answer = 0;
        for (int start = 1; start <= n / 2; ++start) {

            int cnt = n / start;
            int tmpNum = start;
            int sum = 0;
            while (cnt-- > 0 && sum <= n) {
                sum += tmpNum++;
                if (sum == n) {
                    ++answer;
                    break;
                }
            }
        }
        return answer + 1;
    }
}
