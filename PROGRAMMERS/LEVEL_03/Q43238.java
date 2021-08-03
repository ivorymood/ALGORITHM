package PROGRAMMERS.LEVEL_03;

public class Q43238 {

    public static void main(String[] args) {
        /*
        n	times	    return
        6	[7, 10]	    28
        3   [1, 1, 1]   1
        3   [1, 2, 3]   2
         */

        int n = 3;
        int[] times = {1, 1, 1};
        System.out.println(solution(n, times));
    }

    public static long solution(int target, int[] times) {

        long left = 0;
        long right = target * (long)getMax(times);
        return getLowerBound(left, right, target, times);
    }

    public static int getMax(int[] times) {
        int maxTime = 0;
        for (int t : times) {
            maxTime = Math.max(maxTime, t);
        }
        return maxTime;
    }

    public static long getLowerBound(long left, long right, long target, int[] times) {

        while (left < right) {

            long mid = (left + right) / 2;
            long sum = 0;
            for (int t : times) {
                sum += mid / t;
            }

            if (sum >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
}
