package PROGRAMMERS.LEVEL_02;

import java.util.*;

public class Q72412 {

    public static void main(String[] args) {
    /*
    info
    ["java backend junior pizza 150","python frontend senior chicken 210",
    "python frontend senior chicken 150","cpp backend senior pizza 260",
    "java backend junior chicken 80","python backend senior chicken 50"]

    query
    ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200",
    "cpp and - and senior and pizza 250","- and backend and senior and - 150",
    "- and - and - and chicken 100","- and - and - and - 150"]

    result
    [1,1,1,1,2,4]
     */

        String[] info = {"java backend junior pizza 150",
                            "python frontend senior chicken 210",
                            "python frontend senior chicken 150",
                            "cpp backend senior pizza 260",
                            "java backend junior chicken 80",
                            "python backend senior chicken 50"};
        String[] query = {"java and backend and junior and pizza 100",
                            "python and frontend and senior and chicken 200",
                            "cpp and - and senior and pizza 250",
                            "- and backend and senior and - 150",
                            "- and - and - and chicken 100",
                            "- and - and - and - 150"};
        List<Integer> result = solution(info, query);
        for (int num : result) {
            System.out.println(num);
        }
    }

    public static final int SCOREIDX = 4;
    public static List<Integer> solution(String[] info, String[] query) {

        Map<String, List<Integer>> map = new HashMap<>();

        for (String str : info) {
            btr(map, str.split("\\sand\\s|\\s"), new String[SCOREIDX], 0, SCOREIDX);
        }

        for (List<Integer> list : map.values()) {
            Collections.sort(list);
        }

        List<Integer> answer = new ArrayList<>();

        for (String str : query) {
            String[] arrStr = str.split("\\sand\\s|\\s");
            String key = arrToString(Arrays.copyOfRange(arrStr, 0, SCOREIDX));

            List<Integer> list = map.get(key);
            int minIdx = lowerBound(list, Integer.parseInt(arrStr[SCOREIDX]));

            int cnt = minIdx >= 0 ? list.size() - minIdx : 0;
            answer.add(cnt);
        }

        return answer;
    }

    public static String arrToString(String[] arrStr) {
        StringBuffer sb = new StringBuffer();
        for (String s : arrStr) {
            sb.append(s);
        }
        return sb.toString();
    }

    public static int lowerBound(List<Integer> list, int key) {

        if (list == null) {
            return -1;
        }

        int left = 0;
        int right = list.size();
        while (left < right) {
            int mid = (left + right) / 2;

            if (list.get(mid) >= key) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

    public static void btr(Map<String, List<Integer>> map, String[] applicant, String[] res, int idx, int N) {

        if (idx == SCOREIDX) {

            String group = arrToString(res);
            if (!map.containsKey(group)) {
                map.put(group, new ArrayList<>());
            }
            map.get(group).add(Integer.parseInt(applicant[SCOREIDX]));
            return;
        }

        res[idx] = applicant[idx];
        btr(map, applicant, res, idx + 1, N);

        if (!applicant[idx].equals("-")) {
            res[idx] = "-";
            btr(map, applicant, res, idx + 1, N);
        }
    }
}
