// https://programmers.co.kr/learn/courses/30/lessons/84512
// 모음 사전
package PROGRAMMERS.WEEKLY_CHALLENGE;

public class Q84512 {

    public static void main(String[] args) {
        /*
            word	result
            "AAAAE"	6
            "AAAE"	10
            "I"	    1563
            "EIO"	1189
         */

        String word = "I";
        System.out.println(solution(word));
    }

    public static int cnt = 0;

    public static int solution(String word) {

        char[] alphas = {'A', 'E', 'I', 'O', 'U'};
        char[] chars = new char[5];

        if (dfs(alphas, chars, word, 0)) {
            return cnt;
        }

        return -1;
    }

    public static boolean dfs(char[] alphas, char[] chars, String word, int idx) {

        if (idx == chars.length) {
            return false;
        }

        for (char alpha : alphas) {

            ++cnt;
            chars[idx] = alpha;
            if (word.equals(String.valueOf(chars).trim())) {
                return true;
            }
            if (dfs(alphas, chars, word, idx + 1)) {
                return true;
            }
            chars[idx] = ' ';
        }
        return false;
    }
}
