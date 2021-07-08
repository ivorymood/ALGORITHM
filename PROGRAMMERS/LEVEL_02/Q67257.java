package PROGRAMMERS.LEVEL_02;

import java.util.Deque;
import java.util.LinkedList;

public class Q67257 {

    public static void main(String[] args) {
        /*
        expression	            result
        "100-200*300-500+20"	60420
        "50*6-3*2"	            300
         */
        String expression = "50*6-3*2";
        System.out.println(solution(expression));
    }

    public static String[] strNumbers;
    public static String[] strOperators;
    public static Character[] ops = {'+', '-', '*'};

    public static long solution(String expression) {

        strNumbers = expression.split("[-+*]");
        strOperators = expression.split("[0-9]+");

        return permutation(ops, 0);
    }

    public static long permutation(Character[] opOrders, int idx) {
        if (idx == opOrders.length) {
            return getValueWithPriority(opOrders);
        }

        long max = 0;
        for (int i = idx; i < opOrders.length; ++i) {
            swap(opOrders, idx, i);
            max = Math.max(max, Math.abs(permutation(opOrders, idx + 1)));
            swap(opOrders, idx, i);
        }
        return max;
    }

    public static void swap(Character[] operators, int i, int j) {
        Character tmp = operators[i];
        operators[i] = operators[j];
        operators[j] = tmp;
    }

    public static long getValueWithPriority(Character[] opOrders) {

        Deque<Long> numDeq = new LinkedList<>();
        Deque<Character> opDeq = new LinkedList<>();
        numDeq.add(Long.parseLong(strNumbers[0]));
        for (int i = 1; i < strNumbers.length; ++i) {
            numDeq.addLast(Long.parseLong(strNumbers[i]));
            opDeq.addLast(strOperators[i].charAt(0));
        }

        Deque<Long> numTmpDeq = new LinkedList<>();
        Deque<Character> opTmpDeq = new LinkedList<>();

        for (Character order : opOrders) {

            numTmpDeq.addLast(numDeq.pollFirst());
            while (!opDeq.isEmpty()) {

                Character nextOp = opDeq.pollFirst();
                long next = numDeq.pollFirst();

                if (order == nextOp) {
                    long last = numTmpDeq.pollLast();
                    numTmpDeq.addLast(calculate(last, next, nextOp));
                } else {
                    numTmpDeq.addLast(next);
                    opTmpDeq.addLast(nextOp);
                }
            }

            while (!numTmpDeq.isEmpty()) {
                numDeq.addLast(numTmpDeq.pollFirst());
            }
            while (!opTmpDeq.isEmpty()) {
                opDeq.addLast(opTmpDeq.pollFirst());
            }
        }
        return numDeq.pollFirst();
    }

    public static long calculate(long first, long second, char op) {
        if (op == '-') {
            return first - second;
        } else if (op == '+') {
            return first + second;
        } else if (op == '*') {
            return first * second;
        }
        return first;
    }
}