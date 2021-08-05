// https://programmers.co.kr/learn/courses/30/lessons/49189?language=java
// 가장 먼 노드

package PROGRAMMERS.LEVEL_03;

import java.util.*;

public class Q49189 {

    public static void main(String[] args) {
        /*
        n	vertex	                                                    return
        6	[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]	3
         */

        int n = 6;
        int[][] edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
        System.out.println(solution(n, edge));
    }

    public static int solution(int N, int[][] edges) {

        List<List<Integer>> adjacentList = new ArrayList<>();
        for (int i = 0; i <= N; ++i) {
            adjacentList.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adjacentList.get(edge[0]).add(edge[1]);
            adjacentList.get(edge[1]).add(edge[0]);
        }

        return bfs(adjacentList, 1, N);
    }

    public static int bfs(List<List<Integer>> adjacentList, int start, int N) {

        int max = 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);

        int[] dist = new int[N + 1];
        Arrays.fill(dist, -1);
        dist[start] = 0;

        while(!queue.isEmpty()) {

            int now = queue.poll();

            for (int next : adjacentList.get(now)) {

                if(dist[next] >= 0) {
                    continue;
                }

                dist[next] = dist[now] + 1;
                max = dist[next];
                queue.add(next);
            }
        }

        int maxCnt = 0;
        for (int d : dist) {
            if (max == d) {
                ++maxCnt;
            }
        }
        return maxCnt;
    }
}
