package PROGRAMMERS.LEVEL_02;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class Q42890 {

    public static void main(String[] args) {
        /*
        relation
        [["100","ryan","music","2"],
        ["200","apeach","math","2"],
        ["300","tube","computer","3"],
        ["400","con","computer","4"],
        ["500","muzi","music","3"],
        ["600","apeach","music","2"]]

        result
        2
         */
        String[][] relation = {{"100","ryan","music","2"},
                                {"200","apeach","math","2"},
                                {"300","tube","computer","3"},
                                {"400","con","computer","4"},
                                {"500","muzi","music","3"},
                                {"600","apeach","music","2"}};
        System.out.println(solution(relation));
    }

    public static int solution(String[][] relation) {

        int attributeSize = relation[0].length;
        boolean[] include = new boolean[attributeSize];
        Set<Integer> candidateSet = new HashSet<>();

        for (int bit = 1; bit < (1 << attributeSize); ++bit) {

            if (!isMinimal(candidateSet, bit)) {
                continue;
            }

            if (isUnique(relation, include, bit)) {
                candidateSet.add(bit);
            }
        }

        return candidateSet.size();
    }

    public static boolean isMinimal(Set<Integer> candidateSet, int bit) {
        for (Integer candidate : candidateSet) {
            if ((candidate & bit) == candidate) {
                return false;
            }
        }
        return true;
    }

    public static boolean isUnique(String[][] relation, boolean[] include, int bit) {

        Set<String> set = new HashSet<>();
        StringBuilder sb;
        for (String[] tuple : relation) {
            sb = new StringBuilder();
            for (int i = 0; i < include.length; ++i) {
                if ((bit & (1 << i)) > 0) {
                    sb.append(tuple[i]);
                    sb.append(' ');
                }
            }
            if (!set.add(sb.toString())) {
                return false;
            }
        }
        return true;
    }
}
