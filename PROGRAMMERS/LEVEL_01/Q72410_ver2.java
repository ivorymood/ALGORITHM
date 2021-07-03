package PROGRAMMERS.LEVEL_01;

public class Q72410_ver2 {

    public static void main(String[] args) {
       /*
        no	new_id	                        result
        예1	"...!@BaT#*..y.abcdefghijklm"	"bat.y.abcdefghi"
        예2	"z-+.^."	                    "z--"
        예3	"=.="	                        "aaa"
        예4	"123_.def"	                    "123_.def"
        예5	"abcdefghijklmn.p"	            "abcdefghijklmn"
        */

        String new_id = "abcdefghijklmn.p";
        System.out.println(solution(new_id));
    }

    public static String solution(String new_id) {

        // rule 1
        String answer = new_id.toLowerCase();

        // rule 2
        answer = answer.replaceAll("[^a-z0-9-_.]", "");

        // rule 3
        answer = answer.replaceAll("[.]{2,}", ".");

        // rule 4
        answer = answer.replaceAll("^[.]|[.]$", "");

        // rule 5
        if (answer.isEmpty()) {
            answer = "a";
        }

        // rule 6
        if (answer.length() >= 16) {
            answer = answer.substring(0, 15);
            answer = answer.replaceAll("[.]$", "");
        }

        // rule 7
        if (answer.length() <= 2) {
            while (answer.length() < 3) {
                answer += answer.charAt(answer.length() - 1);
            }
        }

        return answer;
    }
}
