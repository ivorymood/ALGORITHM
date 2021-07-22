// https://programmers.co.kr/learn/courses/30/lessons/12951?language=java
// JadenCase 문자열 만들기
package PROGRAMMERS.LEVEL_02;

public class Q12951 {

    public static void main(String[] args) {
        /*
        s	                        return
        "3people unFollowed me  "	"3people Unfollowed Me  "
        "for the last week"	        "For The Last Week"
         */
        String s = "3people unFollowed me  t    t  ";
        System.out.println("[" + solution(s) + "]");
    }

    public static String solution(String s) {

        StringBuilder sb = new StringBuilder();
        String[] arrS = s.toLowerCase().split(" ");
        for (String word : arrS) {
            if (word.length() > 0) {
                sb.append(Character.toUpperCase(word.charAt(0)));
                sb.append(word.substring(1));
            }
            sb.append(" ");
        }

        sb = new StringBuilder(sb.substring(0, sb.length() - 1));
        while (sb.length() < s.length()) {
            sb.append(" ");
        }

        return sb.toString();
    }
}
