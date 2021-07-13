package PROGRAMMERS.LEVEL_02;

import java.util.*;

public class Q42584 {

    public static void main(String[] args) {
        /*
        prices	            return
        [1, 2, 3, 2, 3]	    [4, 3, 1, 1, 0]
         */

        int[] prices = {1, 2, 3, 2, 3};
        int[] result = solution(prices);
        for (int i : result) {
            System.out.println(i);
        }
    }

    public static int[] solution(int[] prices) {

        int[] answer = new int[prices.length];
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < prices.length; ++i) {

            while (!stack.isEmpty() && prices[stack.peek()] > prices[i]) {
                answer[stack.peek()] = i - stack.peek();
                stack.pop();
            }
            stack.push(i);
        }

        while (!stack.isEmpty()) {
            answer[stack.peek()] = prices.length - 1 - stack.peek();
            stack.pop();
        }
        return answer;
    }
}
