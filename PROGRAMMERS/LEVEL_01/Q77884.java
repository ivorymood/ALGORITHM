package PROGRAMMERS.LEVEL_01;

public class Q77884 {

    public static void main(String[] args) {
        /*
        left	right	result
        13	    17	    43
        24	    27	    52
         */
        int left = 13;
        int right = 17;
        System.out.println(solution(left, right));
    }
    public static int solution(int left, int right) {

        int answer = 0;
        for (int num = left; num <= right; ++num) {
            if (countDivisor(num) % 2 == 0) {
                answer += num;
            } else {
                answer -= num;
            }
        }

        return answer;
    }

    public static int countDivisor(int num) {

        int count = 0;
        for (int i = 1; i <= num / i; ++i) {
            if (num % i == 0) {
                if (num / i == i) {
                    ++count;
                } else {
                    count += 2;
                }
            }
        }
        return count;
    }
}
