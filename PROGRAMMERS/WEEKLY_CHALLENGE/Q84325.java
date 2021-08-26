// https://programmers.co.kr/learn/courses/30/lessons/84325
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

        Map<String, String[]> tableMap = new HashMap<>();
        for (String line : table) {

            String[] parts = line.split(" ");
            tableMap.put(parts[0], Arrays.copyOfRange(parts, 1, 6));
        }

        Map<String, Integer> pointMap = new HashMap<>();
        for (int i = 0; i < languages.length; ++i) {
            pointMap.put(languages[i], preference[i]);
        }

        Map<String, Integer> sumMap = new HashMap<>();
        for (Map.Entry<String, String[]> entry: tableMap.entrySet()) {
            String[] points = entry.getValue();
            int sum = 0;
            for (int i = 0; i < points.length; ++i) {

                if (pointMap.containsKey(points[i])) {
                    sum += pointMap.get(points[i]) * (points.length - 1 - i);
                }
            }
            sumMap.put(entry.getKey(), sum);
        }

        List<Map.Entry<String, Integer>> sumList = new ArrayList<>(sumMap.entrySet());
        Collections.sort(sumList, (e1, e2) -> {
            if (e1.getValue() != e2.getValue()) {
                return e2.getValue() - e1.getValue();
            }
            return e1.getKey().compareTo(e2.getKey());
        });

        return sumList.get(0).getKey();
    }
}
