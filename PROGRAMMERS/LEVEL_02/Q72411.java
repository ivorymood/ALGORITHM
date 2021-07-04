package PROGRAMMERS.LEVEL_02;

import java.util.*;

public class Q72411 {
    public static void main(String[] args) {
    /*
        orders	                                            course	    result
        ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]	    [2,3,4]	    ["AC", "ACDE", "BCFG", "CDE"]
        ["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"]	[2,3,5]	    ["ACD", "AD", "ADE", "CD", "XYZ"]
        ["XYZ", "XWY", "WXA"]	                            [2,3,4]	    ["WX", "XY"]
     */
        String[] orders = {"XYZ", "XWY", "WXA"};
        int[] course = {2,3,4};

        List<String> result = solution(orders, course);
        for (String res : result) {
            System.out.println(res);
        }
    }

    public static int maxCnt;
    public static HashMap<String, Integer> map;

    public static List<String> solution(String[] orders, int[] course) {

        map = new HashMap<>();

        for (int i = 0; i < orders.length; ++i) {
            char[] tmp = orders[i].toCharArray();
            Arrays.sort(tmp);
            orders[i] = String.valueOf(tmp);
        }

        PriorityQueue<String> pq = new PriorityQueue<>();

        for (int size : course) {

            maxCnt = 0;
            List<Integer> list = new ArrayList<>();
            for (String order : orders) {
                dfs(order, list, 0, size);
            }

            Iterator<Map.Entry<String, Integer>> iterator = map.entrySet().iterator();
            while (iterator.hasNext()) {
                
                Map.Entry<String, Integer> entry = iterator.next();
                if (maxCnt > 1 && entry.getValue() == maxCnt) {
                    pq.add(entry.getKey());
                }
                iterator.remove();
            }
        }

        List<String> answer = new ArrayList<>();
        while (!pq.isEmpty()) {
            answer.add(pq.poll());
        }
        return answer;
    }

    public static void dfs(String order, List<Integer> idxList, int next, int targetLength) {

        if (idxList.size() == targetLength) {

            StringBuilder sb = new StringBuilder();
            for (int idx : idxList) {
                sb.append(order.charAt(idx));
            }
            String res = sb.toString();

            if (map.containsKey(res)) {
                map.put(res, map.get(res) + 1);
            } else {
                map.put(res, 1);
            }
            maxCnt = Math.max(maxCnt, map.get(res));
            return;
        }

        for (int idx = next; idx < order.length(); ++idx) {
            if (idxList.isEmpty() || idx > idxList.get(idxList.size() - 1)) {
                idxList.add(idx);
                dfs(order, idxList, next + 1, targetLength);
                idxList.remove(idxList.size() - 1);
            }
        }
    }
}


