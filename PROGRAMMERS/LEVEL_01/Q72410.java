package PROGRAMMERS.LEVEL_01;

import java.util.Deque;
import java.util.LinkedList;

public class Q72410 {

    public static void main(String[] args) {
       /*
        no	new_id	                        result
        예1	"...!@BaT#*..y.abcdefghijklm"	"bat.y.abcdefghi"
        예2	"z-+.^."	                    "z--"
        예3	"=.="	                        "aaa"
        예4	"123_.def"	                    "123_.def"
        예5	"abcdefghijklmn.p"	            "abcdefghijklmn"
        */

        String new_id = "=.=";
        System.out.println(solution(new_id));
    }

    public static boolean isAvailableChar(Character c) {

        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
                || c == '-' || c == '_' || c == '.';
    }

    static class DequeWrapper {
        Deque<Character> deque;
        DequeWrapper() {
            this.deque = new LinkedList<>();
        }
    }


    public static void swapQueue(DequeWrapper a, DequeWrapper b) {
        Deque<Character> tmp = a.deque;
        a.deque = b.deque;
        b.deque = tmp;
    }

    public static String solution(String new_id) {

        // rule 1
        new_id = new_id.toLowerCase();

        DequeWrapper f_qw = new DequeWrapper();
        DequeWrapper s_qw = new DequeWrapper();
        for (int i = 0; i < new_id.length(); ++i) {
            f_qw.deque.addLast(new_id.charAt(i));
        }

        // rule 2
        while(!f_qw.deque.isEmpty()) {
            Character c = f_qw.deque.pollFirst();
            if (isAvailableChar(c)) {
                s_qw.deque.addLast(c);
            }
        }

        swapQueue(f_qw, s_qw);

        // rule 3
        while(!f_qw.deque.isEmpty()) {
            Character c = f_qw.deque.pollFirst();
            if (!s_qw.deque.isEmpty()) {
                char last = s_qw.deque.peekLast();
                if (last == '.' && c == '.') {
                    continue;
                }
            }
            s_qw.deque.addLast(c);
        }

        swapQueue(f_qw, s_qw);

        // rule 4
        if (!f_qw.deque.isEmpty() && f_qw.deque.peekFirst() == '.') {
            f_qw.deque.pollFirst();
        }
        if (!f_qw.deque.isEmpty() && f_qw.deque.peekLast() == '.') {
            f_qw.deque.pollLast();
        }

        // rule 5
        if (f_qw.deque.isEmpty()) {
            f_qw.deque.addLast('a');
        }

        // rule 6
        while (!f_qw.deque.isEmpty() && s_qw.deque.size() < 15) {
            s_qw.deque.addLast(f_qw.deque.pollFirst());
        }

        while (s_qw.deque.peekLast() == '.') {
            s_qw.deque.pollLast();
        }

        swapQueue(f_qw, s_qw);
        s_qw.deque.clear();

        // rule 7
        while (f_qw.deque.size() < 3) {
            Character last = f_qw.deque.peekLast();
            f_qw.deque.addLast(last);
        }

        StringBuffer st = new StringBuffer();
        while (!f_qw.deque.isEmpty()) {
            st.append(f_qw.deque.pop());
        }

        return st.toString();
    }
}
