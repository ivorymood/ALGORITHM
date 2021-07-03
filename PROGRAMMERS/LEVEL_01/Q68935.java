package PROGRAMMERS.LEVEL_01;

public class Q68935 {

    public static void main(String[] args) {
        /*
        n	    result
        45	    7
        125	    229
         */
        int n = 45;
        System.out.println(solution(n));
    }

    public static int solution(int n) {

        StringBuffer sb = new StringBuffer();
        while (n / 3 > 0) {
            sb.append(n % 3);
            n /= 3;
        }
        sb.append(n);
        String answer = sb.toString().replaceAll("^[0]{1,}", "");
        return Integer.parseInt(answer, 3);
    }
}
