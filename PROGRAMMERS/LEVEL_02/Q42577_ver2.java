package PROGRAMMERS.LEVEL_02;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class Q42577_ver2 {

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
        Set<String> set = new HashSet<>();

        for (String number : phone_book) {
            for (int i = 0; i < number.length(); ++i) {
                if (set.contains(number.substring(0, i))) {
                    return false;
                }
            }
            set.add(number);
        }
        return true;
    }
}
