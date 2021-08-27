// https://programmers.co.kr/learn/courses/30/lessons/84325
// 직업군 추천하기
package PROGRAMMERS.WEEKLY_CHALLENGE;

import java.util.*;

public class Q84325 {

    public static void main(String[] args) {
        String[] table = {"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"};
        String[] languages = {"PYTHON", "C++", "SQL"};
        int[] preference = {7, 5, 5};

        System.out.println(solution(table, languages, preference));
    }

    public static String solution(String[] table, String[] languages, int[] preference) {

        Map<String, Integer> pointMap = new HashMap<>();
        for (int i = 0; i < languages.length; ++i) {
            pointMap.put(languages[i], preference[i]);
        }

        String answer = "";
        int maxScore = 0;
        for (String line : table) {

            String[] parts = line.split(" ");
            int sum = 0;
            for (int i = 1; i < parts.length; ++i) {
                if (pointMap.containsKey(parts[i])) {
                    sum += pointMap.get(parts[i]) * (parts.length - i);
                }
            }

            if (maxScore < sum
            || (maxScore == sum && answer.compareTo(parts[0]) > 0)) {
                maxScore = sum;
                answer = parts[0];
            }
        }

        return answer;
    }
}
