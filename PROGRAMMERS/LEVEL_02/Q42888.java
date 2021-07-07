package PROGRAMMERS.LEVEL_02;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Q42888 {

    public static void main(String[] args) {

        /*
        record
        ["Enter uid1234 Muzi",
        "Enter uid4567 Prodo",
        "Leave uid1234",
        "Enter uid1234 Prodo",
        "Change uid4567 Ryan"]

        result
        ["Prodo님이 들어왔습니다.",
        "Ryan님이 들어왔습니다.",
        "Prodo님이 나갔습니다.",
        "Prodo님이 들어왔습니다."]
         */

        String[] record = {"Enter uid1234 Muzi",
                        "Enter uid4567 Prodo",
                        "Leave uid1234",
                        "Enter uid1234 Prodo",
                        "Change uid4567 Ryan"};
        List<String> res = solution(record);
        for (String s : res) {
            System.out.println(s);
        }
    }

    static final String ENTER = "Enter";
    static final String LEAVE = "Leave";
    static final String CHANGE = "Change";

    public static List<String> solution(String[] record) {

        Map<String, String> actionMap = new HashMap<>();
        actionMap.put(ENTER, "님이 들어왔습니다.");
        actionMap.put(LEAVE, "님이 나갔습니다.");

        Map<String, String> idMap = new HashMap<>();
        List<String> idMsgList = new ArrayList<>();
        List<String> actionMsgList = new ArrayList<>();

        for (String str : record) {
            String[] cmd = str.split("\\s");

            if (cmd[0].equals(ENTER)) {

                if (idMap.containsKey(cmd[1])) {
                    idMap.put(cmd[1], cmd[2]);
                } else {
                    idMap.put(cmd[1], cmd[2]);
                }

                idMsgList.add(cmd[1]);
                actionMsgList.add(actionMap.get(cmd[0]));

            } else if (cmd[0].equals(LEAVE)) {
                idMsgList.add(cmd[1]);
                actionMsgList.add(actionMap.get(cmd[0]));

            } else if (cmd[0].equals(CHANGE)) {
                idMap.put(cmd[1], cmd[2]);
            }
        }

        List<String> answer = new ArrayList<>();
        for (int i = 0; i < idMsgList.size(); ++i) {
            answer.add(idMap.get(idMsgList.get(i)) + actionMsgList.get(i));
        }
        return answer;
    }
}
