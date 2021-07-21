// https://programmers.co.kr/learn/courses/30/lessons/12909?language=java
// 올바른 괄호

package PROGRAMMERS.LEVEL_02;

public class Q12909 {

    public static void main(String[] args) {
        /*
        s	        answer
        "()()"	    true
        "(())()"	true
        ")()("	    false
        "(()("	    false
         */
        String s = "()()";
        System.out.println(solution(s));
    }

    static boolean solution(String s) {

        int sum = 0;
        for (int i = 0; i < s.length(); ++i) {

            if (s.charAt(i) == '(') {
                ++sum;
            } else {
                --sum;
            }

            if (sum < 0) {
                return false;
            }
        }

        return sum == 0;
    }
}
