// https://programmers.co.kr/learn/courses/30/lessons/17686?language=java
// [3차] 파일명 정렬
package PROGRAMMERS.LEVEL_02;

import java.util.*;

public class Q17686_ver2 {

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

    public static class File implements Comparable<File> {
        String head;
        int number;
        String origin;
        File(String head, int number, String origin) {
            this.head = head;
            this.number = number;
            this.origin = origin;
        }

        @Override
        public int compareTo(File o) {
            if (this.head.compareTo(o.head) != 0) {
                return this.head.compareTo(o.head);
            }
            return this.number - o.number;
        }
    }

    public static String[] solution(String[] files) {

        List<File> fileList = new ArrayList<>();

        for (String strFile : files) {

            int idx = 0;
            while (idx < strFile.length()) {
                char c = strFile.charAt(idx);
                if ('0' <= c && c <= '9') {
                    break;
                }
                ++idx;
            }
            int headEnd = idx;

            while (idx < strFile.length()) {
                char c = strFile.charAt(idx);
                if (!('0' <= c && c <= '9')) {
                    break;
                }
                ++idx;
            }
            int numberEnd = idx;
            fileList.add(new File(strFile.substring(0, headEnd).toUpperCase(),
                    Integer.parseInt(strFile.substring(headEnd, numberEnd)),
                    strFile));
        }

        Collections.sort(fileList);

        String[] answer = new String[fileList.size()];
        for (int i = 0; i < fileList.size(); ++i) {
            answer[i] = fileList.get(i).origin;
        }
        return answer;
    }
}
