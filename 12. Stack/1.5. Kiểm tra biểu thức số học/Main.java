
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String s = sc.nextLine();
            if (check(s)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }

    private static boolean check(String s) {
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ')') {
                char tmp = st.pop();
                boolean thua = true;
                while (tmp != '(') {
                    if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/') {
                        thua = false;
                    }
                    tmp = st.pop();
                }
                if (thua) {
                    return true;
                }
            } else {
                st.push(s.charAt(i));
            }
        }
        return false;
    }
}
