package PROGRAMMERS.LEVEL_02;

import java.util.LinkedList;
import java.util.Queue;

public class Q12978 {

    public static void main(String[] args) {
        /*
        N	road	                                                    K	result
        5	[[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]]	        3	4
        6	[[1,2,1],[1,3,2],[2,3,2],[3,4,3],[3,5,2],[3,5,3],[5,6,1]]	4	4
         */
        int N = 6;
        int[][] road = {{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}};
        int K = 4;

        System.out.println(solution(N, road, K));
    }

    public static int solution(int N, int[][] road, int K) {

        int[][] distArray = new int[N + 1][N + 1];

        for (int[] info : road) {

            if (distArray[info[0]][info[1]] > 0) {
                distArray[info[0]][info[1]] = Math.min(info[2], distArray[info[0]][info[1]]);
            } else {
                distArray[info[0]][info[1]] = info[2];
            }
            if (distArray[info[1]][info[0]] > 0) {
                distArray[info[1]][info[0]] = Math.min(info[2], distArray[info[1]][info[0]]);
            } else {
                distArray[info[1]][info[0]] = info[2];
            }
        }

        return bfs(distArray, K);
    }


    public static int bfs(int[][] distArray, int K) {

        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        boolean[] visit = new boolean[distArray.length];
        visit[1] = true;
        int[] minHour = new int[distArray.length];

        while (!queue.isEmpty()) {
            int now = queue.poll();

            for (int next = 1; next < distArray.length; ++next) {
                int nextRoad = distArray[now][next];
                int nextMoved = minHour[now] + nextRoad;

                if (nextRoad == 0 || nextMoved > K
                        || (visit[next] && minHour[next] < nextMoved)) {
                    continue;
                }

                queue.add(next);
                minHour[next] = nextMoved;
                visit[next] = true;
            }
        }

        int visited = 0;
        for (boolean b : visit) {
            if (b) {
                ++visited;
            }
        }
        return visited;
    }
}
