package PROGRAMMERS.LEVEL_02;

import java.util.LinkedList;
import java.util.Queue;

public class Q42587 {

    public static void main(String[] args) {

        /*
            priorities	        location	return
            [2, 1, 3, 2]	    2	        1
            [1, 1, 9, 1, 1, 1]	0	        5
         */

        int[] priorities = {1, 1, 9, 1, 1, 1};
        int location = 0;
        System.out.println(solution(priorities, location));
    }

    public static class Work {
        int priority;
        int order;
        Work(int priority, int order) {
            this.priority = priority;
            this.order = order;
        }
    }

    public static int solution(int[] priorities, int location) {

        Queue<Work> queue = new LinkedList<>();
        for (int i = 0; i < priorities.length; ++i) {
            queue.add(new Work(priorities[i], i));
        }
        return getPrintOrder(queue, location);
    }

    public static int getPrintOrder(Queue<Work> queue, int location) {

        int printed = 1;
        while(!queue.isEmpty()) {

            Work work = queue.poll();
            if (isBiggerExist(new LinkedList<>(queue), work)) {
                queue.add(work);
                continue;
            }
            if (work.order == location) {
                return printed;
            }
            ++printed;
        }
        return -1;
    }

    public static boolean isBiggerExist(Queue<Work> queue, Work work) {

        while(!queue.isEmpty()) {
            Work next = queue.poll();
            if (next.priority > work.priority) {
                return true;
            }
        }
        return false;
    }
}
