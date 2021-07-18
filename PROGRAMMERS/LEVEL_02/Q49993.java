package PROGRAMMERS.LEVEL_02;

import java.util.Arrays;

public class Q49993 {

    public static void main(String[] args) {
        /*
        skill	skill_trees	                        return
        "CBD"	["BACDE", "CBADF", "AECB", "BDA"]	2
         */
        String skill = "CBD";
        String[] skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
        System.out.println(solution(skill, skill_trees));
    }

    public static int solution(String skill, String[] skill_trees) {

        int[] priority = new int['Z' - 'A' + 1];
        Arrays.fill(priority, -1);

        for (int i = skill.length() - 1; i > 0; --i) {
            priority[skill.charAt(i) - 'A'] = skill.charAt(i - 1) - 'A';
        }

        int answer = 0;
        for (String skillTree : skill_trees) {

            if (rightOrder(skillTree, priority)) {
                ++answer;
            }
        }
        return answer;
    }

    public static boolean rightOrder(String skillTree, int[] priority) {

        boolean[] check = new boolean[priority.length];
        for (int i = 0; i < skillTree.length(); ++i) {

            // 선행 스킬이 있는데 check 안되어있으면 false
            int idx = skillTree.charAt(i) - 'A';
            if (priority[idx] >= 0 && !check[priority[idx]]) {
                return false;
            }
            check[idx] = true;
        }
        return true;
    }
}
