package PROGRAMMERS.LEVEL_01;

public class Q76501 {

    public static void main(String[] args) {
/*
        absolutes	    signs	            result
        [4,7,12]	    [true,false,true]	9
        [1,2,3]	        [false,false,true]	0
 */

        int[] absolutes = {4,7,12};
        boolean[] signs = {true,false,true};

        System.out.println(solution(absolutes, signs));
    }

    public static int solution(int[] absolutes, boolean[] signs) {

        int answer = 0;
        int i = 0;
        for (boolean flag : signs) {
            if (flag) {
                answer += absolutes[i++];
            } else {
                answer -= absolutes[i++];
            }
        }

        return answer;
    }
}
