// https://programmers.co.kr/learn/courses/30/lessons/17684?language=java
// [3차] 압축

package PROGRAMMERS.LEVEL_02;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Q17684 {

    public static void main(String[] args) {
        /*
        msg	                        answer
        KAKAO	                    [11, 1, 27, 15]
        TOBEORNOTTOBEORTOBEORNOT	[20, 15, 2, 5, 15, 18, 14, 15, 20, 27, 29, 31, 36, 30, 32, 34]
        ABABABABABABABAB	        [1, 2, 27, 29, 28, 31, 30]
         */
        String msg = "TOBEORNOTTOBEORTOBEORNOT";
        List<Integer> res = solution(msg);
        for (int i : res) {
            System.out.println(i);
        }
    }

    public static List<Integer> solution(String msg) {

        // initializing dictionary
        Map<String, Integer> dict = new HashMap<>();
        int idx = 0;
        while (idx++ <= 'Z' - 'A') {
            dict.put(Character.toString((char)(idx - 1 + 'A')) , idx);
        }

        int start = 0;
        int end = start + 1;
        int lastSearchIdx = 0;

        List<Integer> answerList = new ArrayList<>();

        while (end <= msg.length()) {

            String target = msg.substring(start, end);

            // when target exist : memorize idx -> check longer word
            if (dict.containsKey(target)) {
                lastSearchIdx = dict.get(target);
                end++;
                continue;
            }

            // when target not exist : add memorized idx on answer list -> check next word
            answerList.add(lastSearchIdx);
            dict.put(target, idx++);
            start = end - 1;
        }
        answerList.add(lastSearchIdx);

        return answerList;
    }
}
