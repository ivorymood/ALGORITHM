package PROGRAMMERS.LEVEL_02;

public class Q60058 {

    public static void main(String[] args) {
        /*
        p	        result
        "(()())()"	"(()())()"
        ")("	    "()"
        "()))((()"	"()(())()"
         */
        String p = "()))((()";
        System.out.println(solution(p));
    }

    public static String solution(String p) {

        return makeRightBrackets(p);
    }

    public static String makeRightBrackets(String w) {
        if (w.equals("")) {
            return w;
        }

        int end = getBalancedEnd(w);
        if (end < 0) {
            return "";
        }

        String u = w.substring(0, end);
        String v = w.substring(end);

        if (isRight(u)) {
            return u + makeRightBrackets(v);
        }

        StringBuilder sb = new StringBuilder();
        sb.append('(');
        sb.append(makeRightBrackets(v));
        sb.append(')');
        sb.append(getReversed(u.substring(1, u.length() - 1)));
        return sb.toString();
    }

    public static int getBalancedEnd(String s) {

        int open = 0;
        int close = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                ++open;
            } else {
                ++close;
            }
            if (open == close) {
                return i + 1;
            }
        }
        return -1;
    }

    public static boolean isRight(String s) {
        int balance = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '(') {
                ++balance;
            } else {
                --balance;
            }

            if (balance < 0) {
                return false;
            }
        }
        return balance == 0;
    }

    public static String getReversed(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                sb.append(')');
            } else {
                sb.append('(');
            }
        }
        return sb.toString();
    }
}
