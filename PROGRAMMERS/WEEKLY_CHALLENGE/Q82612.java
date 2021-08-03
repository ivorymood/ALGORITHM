package PROGRAMMERS.WEEKLY_CHALLENGE;

public class Q82612 {

    public static void main(String[] args) {
        /*
        price	money	count	result
        3	    20	    4	    10
         */

        int price = 3;
        int money = 20;
        int count = 4;
        System.out.println(solution(price, money, count));
    }

    public static long solution(int price, int money, int count) {
        return Math.max((long)price * count * (count + 1) / 2 - money, 0);
    }
}
