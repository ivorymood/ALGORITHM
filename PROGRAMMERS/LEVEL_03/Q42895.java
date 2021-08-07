// https://programmers.co.kr/learn/courses/30/lessons/42895
// N으로 표현

package PROGRAMMERS.LEVEL_03;

import java.util.*;

public class Q42895 {

    public static void main(String[] args) {
        /*
        N	number	return
        5	12	    4
        2	11	    3
         */
        int N = 5;
        int number = 5;
        System.out.println(solution(N, number));
    }

    public static final int MAX_LIMIT = 8;

    public static int solution(int N, int number) {

        List<Set<Integer>> numList = new ArrayList<>();
        numList.add(new HashSet<>());

        int base = 0;
        for (int i = 1; i <= MAX_LIMIT; ++i) {
            base = base * 10 + N;
            numList.add(new HashSet<>());
            numList.get(i).add(base);
        }

        return dfs(numList, 1, number);
    }

    public static int dfs(List<Set<Integer>> numList, int cnt, int target) {

        if (cnt > MAX_LIMIT) {
            return -1;
        }

        for (int i = 1; i < cnt; ++i) {
            for (int num1 : numList.get(i)) {
                for (int num2 : numList.get(cnt - i)) {
                    numList.get(cnt).add(num1 + num2);
                    numList.get(cnt).add(num1 - num2);
                    numList.get(cnt).add(num1 * num2);
                    if (num2 != 0) {
                        numList.get(cnt).add(num1 / num2);
                    }
                }
            }
        }

        if (numList.get(cnt).contains(target)) {
            return cnt;
        }
        return dfs(numList, cnt + 1, target);
    }
}
