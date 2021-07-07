package PROGRAMMERS.LEVEL_02;

public class Q62048 {

    public static void main(String[] args) {
        /*
        W	H	result
        8	12	80

         */

        int W = 8;
        int H = 12;
        System.out.println(solution(W, H));
        System.out.println(3 % 5);
    }

    public static long solution(int w, int h) {
        int gcd = getGcd(w, h);
        long cross = w + h - gcd;
        return (long)w * (long)h - cross;
    }

    public static int getGcd(int A, int B) {
        if (B == 0) {
            return A;
        }
        return getGcd(B, A % B);
    }
}
