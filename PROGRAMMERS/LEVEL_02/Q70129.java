package PROGRAMMERS.LEVEL_02;

import java.util.List;

public class Q70129 {

    public static void main(String[] args) {
    /*
        s	            result
        "110010101001"	[3,8]
        "01110"	        [3,3]
        "1111111"	    [4,1]
     */

        String s = "110010101001";
        int[] result = solution(s);
        for (int i : result) {
            System.out.println(i);
        }
    }

    public static int[] solution(String s) {

        int times = 0;
        int zero = 0;
        while (!s.equals("1")) {

            ++times;

            int first_length = s.length();
            s = s.replaceAll("0", "");
            int second_length = s.length();
            zero += first_length - second_length;

            s = Integer.toBinaryString(second_length);
        }

        return new int[]{times, zero};
    }
}
