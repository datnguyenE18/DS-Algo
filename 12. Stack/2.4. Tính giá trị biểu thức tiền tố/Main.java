
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
        Stack<Integer> st = new Stack<>();
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '+'
                    || s.charAt(i) == '-'
                    || s.charAt(i) == '*'
                    || s.charAt(i) == '/'
                    || s.charAt(i) == '%'
                    || s.charAt(i) == '^') {
                int a = st.peek();
                st.pop();
                int b = st.peek();
                st.pop();
                int tmp = 0;
                switch (s.charAt(i)) {
                    case '+':
                        tmp = b + a;
                        break;
                    case '-':
                        tmp = a - b;
                        break;
                    case '*':
                        tmp = b * a;
                        break;
                    case '/':
                        tmp = a / b;
                        break;
                    case '%':
                        tmp = a % b;
                        break;
                    case '^':
                        tmp = (int) Math.pow(a, b);
                        break;
                }
                st.push(tmp);

            } else {
                st.push(Integer.parseInt(s.charAt(i) + ""));
            }
        }
        System.out.println(st.peek());
    }
}
