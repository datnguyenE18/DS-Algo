
import java.util.*;

public class Main {

    private static void solve(int n, String str) {
        String[] tb = str.split(" ");
        Stack<Long> st = new Stack<>();

        for (int i = tb.length - 1; i >= 0; i--) {
            if (tb[i].equals("")) {
                continue;
            }

            if (tb[i].equals("+") || tb[i].equals("-") || tb[i].equals("*") || tb[i].equals("/")) {
                long a = st.pop();
                long b = st.pop();
                long c;

                switch (tb[i]) {
                    case "+":
                        c = a + b;
                        break;

                    case "-":
                        c = a - b;
                        break;

                    case "*":
                        c = a * b;
                        break;

                    default:
                        c = a / b;
                        break;
                }
                st.push(c);
            } else {
                st.push(Long.parseLong(tb[i]));
            }
        }
        System.out.println(st.peek());
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());

        while (t-- > 0) {
            int N = Integer.parseInt(sc.nextLine());
            String str = sc.nextLine();
            solve(N, str);
        }
    }
}
