package PROGRAMMERS.LEVEL_02;

public class Q42883_ver2 {

    public static void main(String[] args) {
        /*
        number	        k	return
        "1924"	        2	"94"
        "1231234"	    3	"3234"
        "4177252841"	4	"775841"
         */
        String number = "4177252841";
        int k = 4;
        System.out.println(solution(number, k));
    }

    public static String solution(String number, int k) {

        char[] numbers = number.toCharArray();

        for (int i = k; i >= 0; --i) {
            for (int j = k; j < numbers.length; ++j) {
                if (numbers[i] < numbers[j]) {
                    break;
                }
                swap(numbers, i, j);
            }
        }

        return String.valueOf(numbers).substring(k);
    }

    public static void swap(char[] numbers, int a, int b) {
        char tmp = numbers[a];
        numbers[a] = numbers[b];
        numbers[b] = tmp;
    }
}
