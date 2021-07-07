package PROGRAMMERS.LEVEL_02;

import java.util.Stack;

public class Q12973 {

    public static void main(String[] args) {
    /*
    s	    result
    baabaa	1
    cdcd	0
     */

        String s = "cdcd";
        System.out.println(solution(s));
    }

    public static int solution(String s)
    {
        Stack<Character> stack = new Stack<>();
        stack.add(s.charAt(0));
        for (int i = 1; i < s.length(); ++i) {

            if (stack.isEmpty()) {
                stack.add(s.charAt(i));
                continue;
            }

            if (stack.peek() == s.charAt(i)) {
                stack.pop();
            } else {
                stack.add(s.charAt(i));
            }
        }

        return stack.isEmpty() ? 1 : 0;
    }
}
