package PROGRAMMERS.LEVEL_02;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class Q12981 {

    public static void main(String[] args) {

      /*
        n	words	                                                    result
        3	["tank", "kick", "know", "wheel", "land",
            "dream", "mother", "robot", "tank"]	                        [3,3]
        5	["hello", "observe", "effect", "take", "either",
            "recognize", "encourage", "ensure", "establish", "hang",
            "gather", "refer", "reference", "estimate", "executive"]	[0,0]
        2	["hello", "one", "even", "never", "now",
            "world", "draw"]	                                        [1,3]
       */

        int n = 3;
        String[] words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
        int[] result = solution(n, words);
        for (int i : result) {
            System.out.println(i);
        }
    }

    public static class Person {
        int number, turn;

        Person() {}
        Person(int number, int turn) {
            this.number = number;
            this.turn = turn;
        }
    }
    public static int[] solution(int n, String[] words) {
        int[] answer = {0, 0};

        Queue<Person> queue = new LinkedList<>();
        for (int i = 1; i <= n; ++i) {
            queue.add(new Person(i, 0));
        }

        char lastChar = words[0].charAt(0);
        int idx = 0;
        Set<String> set = new HashSet<>();
        while (idx < words.length) {

            Person now = queue.poll();
            ++now.turn;

            String word = words[idx];
            if (word.length() <= 1 || word.charAt(0) != lastChar || !set.add(word)) {
                answer[0] = now.number;
                answer[1] = now.turn;
                return answer;
            }

            lastChar = word.charAt(word.length() - 1);
            queue.add(now);
            ++idx;
        }

        return answer;
    }
}
