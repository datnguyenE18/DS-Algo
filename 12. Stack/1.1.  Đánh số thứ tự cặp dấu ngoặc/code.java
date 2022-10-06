import java.util.Scanner;
import java.util.Stack;

public class Main {
    private static void check(String s) {
        Stack<Character> stc = new Stack<>();
        Stack<Integer> stt = new Stack<>();
        int max = 0, len = s.length();

        for (int i = 0; i < len; i++) {
            char c = s.charAt(i);
            if (c == '(') {
                stc.push(c);
                max++;
                stt.push(max);
                System.out.print(max + " ");
            } else if (c == ')') {
                stc.pop();
                System.out.print(stt.pop() + " ");
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String s = sc.nextLine();
            check(s);
        }
    }

}
