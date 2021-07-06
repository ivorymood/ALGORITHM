package PROGRAMMERS.LEVEL_02;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Stack;

public class Q76502 {

    public static void main(String[] args) {
        /*
        s	        result
        "[](){}"	3
        "}]()[{"	2
        "[)(]"	    0
        "}}}"	    0
         */
        String s = "}]()[{";
        System.out.println(solution(s));
    }

    public static int solution(String s) {

        Deque<Character> deque = new LinkedList<>();
        for (int i = 0; i < s.length(); ++i) {
            deque.addLast(s.charAt(i));
        }

        int answer = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (check(deque)) {
                ++answer;
            }
            deque.addLast(deque.pollFirst());
        }

        return answer;
    }

    public static boolean check(Deque<Character> deque) {

        Deque<Character> newDeque = new LinkedList<>(deque);
        Stack<Character> stack = new Stack<>();

        while (!newDeque.isEmpty()) {
            Character now = newDeque.pollFirst();
            if (now == '(' || now == '{' || now == '[') {
                stack.push(now);
                continue;
            }

            if (stack.isEmpty()) {
                return false;
            }

            Character last = stack.pop();
            if ( !(isPair(last, now, '(', ')')
                    || isPair(last, now, '{', '}')
                    || isPair(last, now, '[', ']') ) ) {
                return false;
            }
        }
        return stack.isEmpty();
    }

    public static boolean isPair(char start, char end, char rightStart, char rightEnd) {
        return start == rightStart && end == rightEnd;
    }
}
