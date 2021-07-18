package PROGRAMMERS.LEVEL_02;

public class Q12980 {
    public static void main(String[] args) {
        /*
        N	    result
        5	    2
        6	    2
        5000	5
         */
        int N = 5000;
        System.out.println(solution(N));
    }

    public static int solution(int n) {

        int cnt = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                n -= 1;
                ++cnt;
            }
            n /= 2;
        }
        return cnt;
    }
}
