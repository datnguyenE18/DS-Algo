
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String s = sc.nextLine();
            Result(s);
        }
    }

    public static void Result(String s) {
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (st.empty()) {
                st.add(s.charAt(i));
            } else {
                if (st.peek() == '[' && s.charAt(i) == ']') {
                    st.pop();
                } else {
                    st.add(s.charAt(i));
                }
            }

        }
        int left = 0, right = 0;
        while (!st.empty()) {
            if (st.peek() == '[') {
                left++;
                st.pop();
            } else if (st.peek() == ']') {
                right++;
                st.pop();
            }
        }
        int sum = left % 2 + left / 2 + right / 2 + right % 2;
        System.out.println(sum);
    }
}
