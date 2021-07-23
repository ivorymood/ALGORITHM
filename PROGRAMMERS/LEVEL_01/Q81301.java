// https://programmers.co.kr/learn/courses/30/lessons/81301
// 숫자 문자열과 영단어
package PROGRAMMERS.LEVEL_01;

public class Q81301 {

    public static void main(String[] args) {
        /*
            s	                result
            "one4seveneight"	1478
            "23four5six7"	    234567
            "2three45sixseven"	234567
            "123"	            123
         */
        String s = "one4seveneight";
        System.out.println(solution(s));
    }

    public static int solution(String s) {

        String[] numbers = {"zero", "one", "two", "three", "four",
                            "five", "six", "seven", "eight", "nine"};

        for (int i = 0; i < numbers.length; ++i) {
            s = s.replaceAll(numbers[i], i + "");
        }
        return Integer.parseInt(s);
    }
}
