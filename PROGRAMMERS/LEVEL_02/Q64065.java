package PROGRAMMERS.LEVEL_02;

import java.util.*;

public class Q64065 {
    public static void main(String[] args) {
        /*
        s	                            result
        "{{2},{2,1},{2,1,3},{2,1,3,4}}"	[2, 1, 3, 4]
        "{{1,2,3},{2,1},{1,2,4,3},{2}}"	[2, 1, 3, 4]
        "{{20,111},{111}}"	            [111, 20]
        "{{123}}"	                    [123]
        "{{4,2,3},{3},{2,3,4,1},{2,3}}"	[3, 2, 4, 1]
         */

        String s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
        List<Integer> res = solution(s);
        for (int i : res) {
            System.out.println(i);
        }
    }

    public static List<Integer> solution(String s) {

        String[] arrSubset = s.substring(2, s.length() - 2).split("},\\{");
        Arrays.sort(arrSubset, (a, b) -> a.length() - b.length());

        List<Integer> answer = new ArrayList<>();
        Set<String> passed = new HashSet<>();
        for (String subset : arrSubset) {

            String[] numbers = subset.split(",");
            for (String num : numbers) {
                if (passed.add(num)) {
                    answer.add(Integer.parseInt(num));
                }
            }
        }
        return answer;
    }

}
