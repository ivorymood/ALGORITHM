package PROGRAMMERS.LEVEL_02;

public class Q12899 {

    public static void main(String[] args) {
    /*
    n	result
    1	1
    2	2
    3	4
    4	11
     */
        int n = 100;
        System.out.println(solution(n));
    }

    public static String solution(int n) {

        String[] num = {"4", "1", "2"};
        StringBuilder sb = new StringBuilder();
        while(n > 0) {
            int rest = n % 3;
            n /= 3;

            if (rest == 0) {
                --n;
            }
            sb.insert(0, num[rest]);
        }
        return sb.toString();
    }
}
