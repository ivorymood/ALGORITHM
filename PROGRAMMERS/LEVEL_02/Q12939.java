// https://programmers.co.kr/learn/courses/30/lessons/12939
// 최댓값과 최솟값
package PROGRAMMERS.LEVEL_02;

public class Q12939 {

    public static void main(String[] args) {
        /*
        s	            return
        "1 2 3 4"	    "1 4"
        "-1 -2 -3 -4"	"-4 -1"
        "-1 -1"	        "-1 -1"
         */
        String s = "1 2 3 4";
        System.out.println(solution(s));
    }

    public static String solution(String s) {

        String[] numbers = s.split(" ");
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;

        for (String strNum : numbers) {
            int n = Integer.parseInt(strNum);
            max = Math.max(max, n);
            min = Math.min(min, n);
        }

        return min + " " + max;
    }
}
