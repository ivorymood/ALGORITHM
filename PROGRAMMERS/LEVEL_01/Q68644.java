package PROGRAMMERS.LEVEL_01;

import java.util.SortedSet;
import java.util.TreeSet;

public class Q68644 {

    public static void main(String[] args) {
        /*
        numbers	        result
        [2,1,3,4,1]	    [2,3,4,5,6,7]
        [5,0,2,7]	    [2,5,7,9,12]
         */

        int[] numbers = {2,1,3,4,1};
        int[] answer = solution(numbers);
        for (int num : answer) {
            System.out.println(num);
        }
    }

    public static int[] solution(int[] numbers) {

        SortedSet<Integer> set = new TreeSet<>();
        for (int i = 0; i < numbers.length - 1; ++i) {
            for (int j = i + 1; j < numbers.length; ++j) {
                set.add(numbers[i] + numbers[j]);
            }
        }

        int[] answer = new int[set.size()];
        int i = 0;
        for (Integer num : set) {
            answer[i++] = num;
        }

        return answer;
    }
}
