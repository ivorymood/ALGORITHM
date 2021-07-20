// https://programmers.co.kr/learn/courses/30/lessons/17683?language=java
// 방금그곡

package PROGRAMMERS.LEVEL_02;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Q17683 {

    public static void main(String[] args) {
        /*
        m	                musicinfos	                                                answer
        "ABCDEFG"	        ["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]	"HELLO"
        "CC#BCC#BCC#BCC#B"	["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]	"FOO"
        "ABC"	            ["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]  "WORLD"
         */
        String m = "CC#BCC#BCC#BCC#B";
        String[] musicinfos = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};

        System.out.println(solution(m, musicinfos));
    }

    public static class Music implements Comparable<Music>{
        int runningTime;
        String title;
        String playedNote;

        Music(int runningTime, String title, String playedNote) {
            this.runningTime = runningTime;
            this.title = title;
            this.playedNote = playedNote;
        }

        @Override
        public int compareTo(Music o) {

            return o.playedNote.length() - this.playedNote.length();
        }
    }

    public static String solution(String m, String[] musicinfos) {

        List<Music> musicList = new ArrayList<>();
        for (String info : musicinfos) {

            String[] str = info.split(",");

            // get music running time
            String[] start = str[0].split(":");
            String[] end = str[1].split(":");
            int startTime = 60 * Integer.parseInt(start[0]) + Integer.parseInt(start[1]);
            int endTime = 60 * Integer.parseInt(end[0]) + Integer.parseInt(end[1]);
            int runningTime = endTime - startTime;

            // get actually played music note
            String musicNote = getImprovedMusicNote(str[3]);
            StringBuilder sb = new StringBuilder();
            int quotient = runningTime / musicNote.length();
            int remainder = runningTime % musicNote.length();
            while (quotient-- > 0) {
                sb.append(musicNote);
            }
            sb.append(musicNote, 0, remainder);

            musicList.add(new Music(runningTime, str[2], sb.toString()));
        }

        String targetNote = getImprovedMusicNote(m);
        List<Music> answerList = new ArrayList<>();
        for (Music music : musicList) {
            if (music.playedNote.contains(targetNote)) {
                answerList.add(music);
            }
        }

        if (answerList.isEmpty()) {
            return "(None)";
        }
        Collections.sort(answerList);
        return answerList.get(0).title;
    }

    // convert X# -> x (lowercase)
    public static String getImprovedMusicNote(String musicNote) {

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < musicNote.length() - 1; ++i) {
            char c = musicNote.charAt(i);
            if (c == '#') {
                continue;
            }
            sb.append(musicNote.charAt(i + 1) == '#' ? Character.toLowerCase(c) : c);
        }
        if (musicNote.charAt(musicNote.length() - 1) != '#') {
            sb.append(musicNote.charAt(musicNote.length() - 1));
        }
        return sb.toString();
    }
}
