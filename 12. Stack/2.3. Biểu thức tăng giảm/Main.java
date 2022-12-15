
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String s = sc.next();
            Result(s);
        }
    }

    public static void Result(String s) {
        Stack<Integer> st = new Stack<>();
        st.add(1);
        int r = 2;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'D') {
                st.add(r);
                r++;
            }
            if (s.charAt(i) == 'I') {
                while (!st.empty()) {
                    System.out.print(st.peek());
                    st.pop();
                }
                st.add(r);
                r++;
            }
        }
        while (!st.empty()) {
            System.out.print(st.peek());
            st.pop();
        }
        System.out.println();
    }
}
