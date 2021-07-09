package PROGRAMMERS.LEVEL_02;

import java.util.LinkedList;
import java.util.List;

public class Q42860 {

    public static void main(String[] args) {
        /*
        name	    return
        "JEROEN"	56
        "JAN"	    23
         */

        String name = "JAN";
        System.out.println(solution(name));
    }

    public static int solution(String name) {

        final int LEN = name.length();
        int answer = 0;
        List<Integer> toGoIndexList = new LinkedList<>();
        for (int i = 0; i < LEN; ++i) {
            char c = name.charAt(i);
            if (c != 'A') {
                toGoIndexList.add(i);
                answer += getUpDownMove(c);
            }
        }

        int nowIdx = 0;
        while (!toGoIndexList.isEmpty()) {

            int minDist = LEN;
            int order = 0;
            for (int i = 0; i < toGoIndexList.size(); ++i) {

                int nextIdxTmp = toGoIndexList.get(i);
                int dist;
                if (nowIdx > nextIdxTmp) {
                    dist = nowIdx - nextIdxTmp;
                } else {
                    dist = Math.min(nextIdxTmp - nowIdx, nowIdx + LEN - nextIdxTmp);
                }

                if (minDist > dist) {
                    minDist = dist;
                    order = i;
                }
            }

            answer += minDist;
            nowIdx = toGoIndexList.get(order);
            toGoIndexList.remove(order);
        }
        return answer;
    }

    public static int getUpDownMove(char alpha) {
        if (alpha - 'A' <= ('Z' - 'A') / 2) {
            return alpha - 'A';
        } else {
            return 'Z' - alpha + 1;
        }
    }
}
