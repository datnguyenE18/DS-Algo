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
        Scanner sc = new Scanner(s);
        Stack<Integer> st = new Stack<>();
        int kq = 0;
        st.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(')
                st.push(i);
            else {
                st.pop();
                if (!st.empty()) {
                    int j = st.peek();
                    kq = Integer.max(kq, i - j);
                } else
                    st.push(i);
            }
        }
        System.out.println(kq);
    }

}
