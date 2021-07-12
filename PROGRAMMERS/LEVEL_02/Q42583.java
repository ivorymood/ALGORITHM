package PROGRAMMERS.LEVEL_02;

import java.util.LinkedList;
import java.util.Queue;

public class Q42583 {

    public static void main(String[] args) {
        /*
        bridge_length	weight	truck_weights	                    return
        2	            10	    [7,4,5,6]	                        8
        100	            100	    [10]	                            101
        100	            100	    [10,10,10,10,10,10,10,10,10,10]	    110
         */
        int bridge_length = 2;
        int weight = 10;
        int[] truck_weights = {7,4,5,6};
        System.out.println(solution(bridge_length, weight, truck_weights));
    }

    public static class Truck {
        int comeInTime;
        int weight;
        Truck(int comeInTime, int weight) {
            this.comeInTime = comeInTime;
            this.weight = weight;
        }
    }

    public static int solution(int bridge_length, int weight, int[] truck_weights) {

        Queue<Truck> queue = new LinkedList<>();
        int time = 0;
        int currentWeightSum = 0;
        int idx = 0;
        while (idx < truck_weights.length || !queue.isEmpty()) {
            ++time;

            if (!queue.isEmpty() && time - queue.peek().comeInTime >= bridge_length) {
                currentWeightSum -= queue.poll().weight;
            }

            if (queue.size() < bridge_length
                && idx < truck_weights.length
                && currentWeightSum + truck_weights[idx] <= weight) {
                queue.add(new Truck(time, truck_weights[idx]));
                currentWeightSum += truck_weights[idx];
                ++idx;
            }
        }
        return time;
    }
}
