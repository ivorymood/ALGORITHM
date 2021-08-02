// https://programmers.co.kr/learn/courses/30/lessons/17676?language=java
// [1차] 추석 트래픽
package PROGRAMMERS.LEVEL_03;

import java.util.*;

public class Q17676 {

    public static void main(String[] args) {

        /*
            lines                                   result
            "2016-09-15 01:00:04.001 2.0s",
            "2016-09-15 01:00:07.000 2s"            1

            "2016-09-15 01:00:04.002 2.0s",
            "2016-09-15 01:00:07.000 2s"            2

            "2016-09-15 20:59:57.421 0.351s",
            "2016-09-15 20:59:58.233 1.181s",
            "2016-09-15 20:59:58.299 0.8s",
            "2016-09-15 20:59:58.688 1.041s",
            "2016-09-15 20:59:59.591 1.412s",
            "2016-09-15 21:00:00.464 1.466s",
            "2016-09-15 21:00:00.741 1.581s",
            "2016-09-15 21:00:00.748 2.31s",
            "2016-09-15 21:00:00.966 0.381s",
            "2016-09-15 21:00:02.066 2.62s"         7
         */

        String[] lines = {"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"};
        System.out.println(solution(lines));
    }

    public enum TType {
        START(0), END(1);

        private int value;

        TType(int value) {
            this.value = value;
        }

        public int getValue() {
            return value;
        }
    }

    public static class TimeMark implements Comparable<TimeMark> {
        int time;
        TType type;

        TimeMark(int time, TType type) {
            this.time = time;
            this.type = type;
        }

        @Override
        public int compareTo(TimeMark o) {

            if (this.time != o.time) {
                return this.time - o.time;
            }
            return this.type.getValue() - o.type.getValue();
        }
    }

    public static int solution(String[] lines) {

        PriorityQueue<TimeMark> pq = new PriorityQueue<>();

        for (String line : lines) {

            String[] parts = line.split(" ");
            String[] strEnds = parts[1].split("[:.]");

            int end = Integer.parseInt(strEnds[0]);
            end = end * 60 + Integer.parseInt(strEnds[1]);
            end = end * 60 + Integer.parseInt(strEnds[2]);
            end = end * 1000 + Integer.parseInt(strEnds[3]);
            pq.add(new TimeMark(end + 999, TType.END));

            String strTime = String.format("%-4s", parts[2].replaceAll("[.s]", "")).replace(' ', '0');
            int start = end - Integer.parseInt(strTime) + 1;
            pq.add(new TimeMark(start, TType.START));
        }

        int maxCnt = 0;
        int cnt = 0;
        while (!pq.isEmpty()) {

            TimeMark tm = pq.poll();
            if (tm.type == TType.START) {
                ++cnt;
            } else {
                --cnt;
            }
            maxCnt = Math.max(maxCnt, cnt);
        }
        return maxCnt;
    }
}
