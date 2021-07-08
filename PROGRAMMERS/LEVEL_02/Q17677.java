package PROGRAMMERS.LEVEL_02;

import java.util.HashMap;
import java.util.Map;

public class Q17677 {

    public static void main(String[] args) {
        /*
        str1	    str2	    answer
        FRANCE	    french	    16384
        handshake	shake hands	65536
        aa1+aa2	    AAAA12	    43690
        E=M*C^2	    e=m*c^2	    65536
         */
        String str1 = "E=M*C^2";
        String str2 = "e=m*c^2";
        System.out.println(solution(str1, str2));
    }

    public static int solution(String str1, String str2) {

        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();
        Map<String, Integer> map1 = new HashMap<>();
        Map<String, Integer> map2 = new HashMap<>();

        for (int i = 0; i < str1.length() - 1; ++i) {
            String tmp = str1.substring(i, i + 2);
            if (map1.containsKey(tmp)) {
                map1.put(tmp, map1.get(tmp) + 1);
            } else {
                map1.put(tmp, 1);
            }
        }
        for (int i = 0; i < str2.length() - 1; ++i) {
            String tmp = str2.substring(i, i + 2);
            if (map2.containsKey(tmp)) {
                map2.put(tmp, map2.get(tmp) + 1);
            } else {
                map2.put(tmp, 1);
            }
        }

        double minSum = 0;
        double maxSum = 0;
        for (char i = 'a'; i <= 'z'; ++i) {
            for (char j = 'a'; j <= 'z'; ++j) {

                String tmp = "" + i + j;
                int cnt1 = map1.getOrDefault(tmp, 0);
                int cnt2 = map2.getOrDefault(tmp, 0);
                minSum += Math.min(cnt1, cnt2);
                maxSum += Math.max(cnt1, cnt2);
            }
        }

        double result = maxSum == 0 ? 1 : minSum / maxSum;
        return (int)(result * 65536L);
    }
}
