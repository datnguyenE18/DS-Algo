import java.util.Scanner;
import java.util.Stack;

public class Main {
    private static void checkNgoac(String s) {
        Stack<Character> st = new Stack<>();
        boolean check = true;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '[' || c == '{')
                st.add(c);
            else if (c == ')' || c == ']' || c == '}') {
                if (st.empty()) {
                    check = false;
                    break;
                } else if ((c == ')' && st.peek() == '(' ||
                        c == ']' && st.peek() == '[' ||
                        c == '}' && st.peek() == '{') && !st.empty())
                    st.pop();
                else {
                    check = false;
                    break;
                }
            }
        }
        if (check && st.empty() && s.charAt(len - 1) == '.')
            System.out.println("YES");
        else
            System.out.println("NO");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String s = sc.nextLine();
            checkNgoac(s);
        }
    }

}