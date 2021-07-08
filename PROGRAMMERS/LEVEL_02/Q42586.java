package PROGRAMMERS.LEVEL_02;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;
import java.util.function.UnaryOperator;

public class Q42586 {

    public static void main(String[] args) {
        /*
        progresses	                speeds	            return
        [93, 30, 55]	            [1, 30, 5]	        [2, 1]
        [95, 90, 99, 99, 80, 99]	[1, 1, 1, 1, 1, 1]	[1, 3, 2]
         */
        int[] progresses = {95, 90, 99, 99, 80, 99};
        int[] speeds = {1, 1, 1, 1, 1, 1};
        List<Integer> res = solution(progresses, speeds);
        for (int i : res) {
            System.out.println(i);
        }
    }

    public static List<Integer> solution(int[] progresses, int[] speeds) {

        List<Integer> answer = new ArrayList<>();
        int len = progresses.length;
        int idx = 0;
        int past = 0;
        while (idx < len) {

            int beforeIdx = idx;
            past += (int)Math.ceil((100 - getDone(progresses[idx], speeds[idx], past)) / speeds[idx]);
            while (idx < len && 100 <= getDone(progresses[idx], speeds[idx], past)) {
                ++idx;
            }

            answer.add(idx - beforeIdx);
        }

        return answer;
    }

    public static double getDone(double progress, double speed, double past) {
        return progress + speed * past;
    }
}
