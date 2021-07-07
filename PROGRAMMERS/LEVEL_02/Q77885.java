package PROGRAMMERS.LEVEL_02;

public class Q77885 {

    public static void main(String[] args) {
        /*
        numbers	result
        [2,7]	[3,11]
         */
        long[] numbers = {2, 7};
        long[] result = solution(numbers);
        for (long l : result) {
            System.out.println(l);
        }
    }

    public static long[] solution(long[] numbers) {

        long[] answer = new long[numbers.length];

        for (int i = 0; i < numbers.length; ++i) {

            if (numbers[i] % 2 == 0) {
                answer[i] = numbers[i] + 1L;
                continue;
            }

            StringBuilder binarySb = new StringBuilder();
            binarySb.append('0');
            binarySb.append(Long.toBinaryString(numbers[i]));
            int lastZeroIdx = binarySb.lastIndexOf("0");
            binarySb.setCharAt(lastZeroIdx, '1');
            binarySb.setCharAt(lastZeroIdx + 1, '0');

            answer[i] = Long.parseLong(binarySb.toString(), 2);
        }

        return answer;
    }
}
