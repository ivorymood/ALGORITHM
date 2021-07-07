package PROGRAMMERS.LEVEL_02;

import java.util.ArrayList;
import java.util.List;

public class Q1835 {
    public static void main(String[] args) {
    /*
        n	data	            answer
        2	["N~F=0", "R~T>2"]	3648
        2	["M~C<2", "C~M>1"]	0
     */
        int n = 2;
        String[] data = {"N~F=0", "R~T>2"};

        System.out.println(solution(n, data));
    }

    public static int cnt;
    public static int solution(int n, String[] data) {

        char[] friends = "ACFJMNRT".toCharArray();
        permutation(friends, data, 0);
        return cnt;
    }

    public static void permutation(char[] friends, String[] data, int idx) {
        if (idx == friends.length - 1) {
            if (check(friends, data)) {
                ++cnt;
            }
            return;
        }

        for (int i = idx; i < friends.length; ++i) {
            swap(friends, idx, i);
            permutation(friends, data, idx + 1);
            swap(friends, idx, i);
        }
    }

    public static void swap(char[] array, int a, int b) {
        char tmp = array[a];
        array[a] = array[b];
        array[b] = tmp;
    }

    public static boolean check(char[] friends, String[] data) {
        int[] order = new int[26];
        for (int i = 0; i < friends.length; ++i) {
            order[friends[i] - 'A'] = i;
        }

        for (String s : data) {
            int aPos = order[s.charAt(0) - 'A'];
            int bPos = order[s.charAt(2) - 'A'];

            int between = Math.abs(aPos - bPos) - 1;
            char op = s.charAt(3);
            int dist = s.charAt(4) - '0';

            if ((op == '>' && !(between > dist))
                || (op == '<' && !(between < dist))
                || (op == '=' && between != dist)) {
                return false;
            }
        }

        return true;
    }
}
