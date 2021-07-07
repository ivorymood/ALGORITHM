package PROGRAMMERS.LEVEL_02;

import java.util.Arrays;

public class Q42577_ver1 {

    public static void main(String[] args) {
        /*
        phone_book	                        return
        ["119", "97674223", "1195524421"]	false
        ["123","456","789"]	                true
        ["12","123","1235","567","88"]	    false
         */
        String[] phone_book = {"119", "97674223", "1195524421"};

        System.out.println(solution(phone_book));
    }

    public static boolean solution(String[] phone_book) {

        Arrays.sort(phone_book);

        for (int i = 1; i < phone_book.length; ++i) {
            if (phone_book[i].startsWith(phone_book[i - 1])) {
                return false;
            }
        }
        return true;
    }
}
