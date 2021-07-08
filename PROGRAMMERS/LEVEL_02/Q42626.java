package PROGRAMMERS.LEVEL_02;

import java.util.PriorityQueue;

public class Q42626 {

    public static void main(String[] args) {
    /*
    scoville	K	return
    [1, 2, 3, 9, 10, 12]	7	2
     */
        int[] scoville = {1, 2, 3, 9, 10, 12};
        int K = 7;
        System.out.println(solution(scoville, K));
    }

    public static int solution(int[] scoville, int K) {

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int food : scoville) {
            pq.add(food);
        }

        int answer = 0;
        while (!pq.isEmpty() && pq.peek() < K) {

            if (pq.size() < 2) {
                return -1;
            }

            pq.add(pq.poll() + pq.poll() * 2);
            ++answer;
        }
        return answer;
    }
}
