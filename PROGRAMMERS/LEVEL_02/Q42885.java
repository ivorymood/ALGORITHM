package PROGRAMMERS.LEVEL_02;

import java.util.Arrays;

public class Q42885 {

    public static void main(String[] args) {
        /*
        people	            limit	return
        [70, 50, 80, 50]	100	    3
        [70, 80, 50]	    100	    3
         */
        int[] people = {70, 50, 80, 50};
        int limit = 100;
        System.out.println(solution(people, limit));
    }

    public static int solution(int[] people, int limit) {

        Arrays.sort(people);
        int boat = 0;
        int low = 0;
        int high = people.length - 1;

        while (low <= high) {

            if (people[high] + people[low] <= limit) {
                ++low;
            }
            --high;
            ++boat;
        }

        return boat;
    }
}
