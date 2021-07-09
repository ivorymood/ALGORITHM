package PROGRAMMERS.LEVEL_02;

import java.util.Stack;

public class Q42883_ver1 {

    public static void main(String[] args) {
        /*
        number	        k	return
        "1924"	        2	"94"
        "1231234"	    3	"3234"
        "4177252841"	4	"775841"
         */
        String number = "4177252841";
        int k = 4;
        System.out.println(solution(number, k));
    }

    public static String solution(String number, int k) {

        StringBuilder sb = new StringBuilder(number);

        while (k > 0) {
            if (!eraseNum(sb)) {
                return sb.substring(0, sb.length() - k);
            }
            --k;
        }
        return sb.toString();
    }

    public static boolean eraseNum(StringBuilder sb) {

        int idx = 0;
        while (idx < sb.length() - 1) {
            int now = sb.charAt(idx) - '0';
            int next = sb.charAt(idx + 1) - '0';
            if (now < next) {
                sb.delete(idx, idx + 1);
                return true;
            }
            ++idx;
        }
        return false;
    }
}
