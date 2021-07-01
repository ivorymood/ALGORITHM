package PROGRAMMERS.LEVEL_01;

class Q77484 {
    public static void main(String[] args) {
        /*
        lottos	                win_nums	                result
        [44, 1, 0, 0, 31, 25]	[31, 10, 45, 1, 6, 19]	    [3, 5]
        [0, 0, 0, 0, 0, 0]	    [38, 19, 20, 40, 15, 25]	[1, 6]
        [45, 4, 35, 20, 3, 9]	[20, 9, 3, 45, 4, 35]	    [1, 1]
         */

        /*
        int[] lottos = {44, 1, 0, 0, 31, 25};
        int[] win_nums = {31, 10, 45, 1, 6, 19};
        */
        int[] lottos = {0, 0, 0, 0, 0, 0};
        int[] win_nums = {38, 19, 20, 40, 15, 25};
/*
        int[] lottos = {45, 4, 35, 20, 3, 9};
        int[] win_nums = {20, 9, 3, 45, 4, 35};
        */

        int[] result = solution(lottos, win_nums);

        System.out.format("%d, %d", result[0], result[1]);
    }

    public static boolean isCertain(int lotto, int[] win_nums) {

        for (int num : win_nums) {
            if (lotto == num) {
                return true;
            }
        }
        return false;
    }

    public static int[] solution(int[] lottos, int[] win_nums) {

        int zero = 0;
        int certain = 0;

        for (int lotto : lottos) {
            if (lotto == 0) {
                ++zero;
            } else if (isCertain(lotto, win_nums)) {
                ++certain;
            }
        }
        int min_rank = Math.min(6, 7 - certain);
        int max_rank = Math.min(6, 7 - (certain + zero));
        return new int[]{max_rank, min_rank};
    }
}