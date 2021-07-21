// https://programmers.co.kr/learn/courses/30/lessons/17686?language=java
// [3차] 파일명 정렬
package PROGRAMMERS.LEVEL_02;

import java.util.*;

public class Q17686_ver1 {

    public static void main(String[] args) {
        /*
        입력: ["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"]
        출력: ["img1.png", "IMG01.GIF", "img02.png", "img2.JPG", "img10.png", "img12.png"]

        입력: ["F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"]
        출력: ["A-10 Thunderbolt II", "B-50 Superfortress", "F-5 Freedom Fighter", "F-14 Tomcat"]
         */
        String[] files = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
        String[] res = solution(files);
        for (String str : res) {
            System.out.println(str);
        }
    }

    public static class FileComparator implements Comparator<String> {

        @Override
        public int compare(String o1, String o2) {

            int o1_idx = 0;
            int o2_idx = 0;
            while (o1_idx < o1.length() && !Character.isDigit(o1.charAt(o1_idx))) {
                ++o1_idx;
            }
            while (o2_idx < o2.length() && !Character.isDigit(o2.charAt(o2_idx))) {
                ++o2_idx;
            }
            int cmp = o1.substring(0, o1_idx).toUpperCase().compareTo(o2.substring(0, o2_idx).toUpperCase());
            if (cmp != 0) {
                return cmp;
            }

            int o1_headEnd = o1_idx;
            int o2_headEnd = o2_idx;
            while (o1_idx < o1.length() && Character.isDigit(o1.charAt(o1_idx))) {
                ++o1_idx;
            }
            while (o2_idx < o2.length() && Character.isDigit(o2.charAt(o2_idx))) {
                ++o2_idx;
            }
            int o1_num = Integer.parseInt(o1.substring(o1_headEnd, o1_idx));
            int o2_num = Integer.parseInt(o2.substring(o2_headEnd, o2_idx));
            return o1_num - o2_num;
        }
    }

    public static String[] solution(String[] files) {
        Arrays.sort(files, new FileComparator());
        return files;
    }
}
