// https://programmers.co.kr/learn/courses/30/lessons/17687?language=java
// [3차] n진수 게임
package PROGRAMMERS.LEVEL_02;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Q17687 {
    public static void main(String[] args) {
        /*
        n	t	m	p	result
        2	4	2	1	"0111"
        16	16	2	1	"02468ACE11111111"
        16	16	2	2	"13579BDF01234567"
         */
        int n = 16;
        int t = 16;
        int m = 2;
        int p = 2;
        System.out.println(solution(n, t, m, p));
    }

    public static String solution(int n, int t, int m, int p) {

        String numbers = "0123456789ABCDEF";
        StringBuilder sb = new StringBuilder();

        Queue<Character> queue = new LinkedList<>();
        Stack<Integer> stack = new Stack<>();
        int cnt = 0;
        int idx = 0;
        int number = 1;
        queue.add('0');

        while (cnt < t) {

            // fill queue with characters of increasing number(which is presented by given numeral system)
            while (queue.size() < m * 2) {
                int tmp = number++;
                while (tmp > 0) {
                    stack.add(tmp % n);
                    tmp /= n;
                }
                while (!stack.isEmpty()) {
                    queue.add(numbers.charAt(stack.pop()));
                }
            }

            // when its turn -> append character to answer
            if (idx % m + 1 == p) {
                sb.append(queue.peek());
                ++cnt;
            }

            queue.poll();
            ++idx;
        }

        return sb.toString();
    }
}
