
import java.util.*;

public class Main {

    private static void solve(String s) {
        ArrayList<String> lst = new ArrayList<>();
        Stack<Character> st = new Stack<>();
        Boolean[] flag = new Boolean[s.length()];

        for (int i = 0; i < s.length(); i++) {
            flag[i] = true;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == '(') {
                st.push(c);
                lst.add("-1");
            } else if (c == ')') {
                if (!st.empty() && st.peek() == '(') {
                    for (int j = i; j >= 0; j--) {
                        if (s.charAt(j) == '(' && flag[j]) {
                            lst.set(j, "0");
                            flag[j] = false;
                            break;
                        }
                    }
                    lst.add("1");
                    st.pop();
                } else if (st.empty() || st.peek() != '(') {
                    lst.add("-1");
                }
            } else {
                lst.add(c + "");
            }
        }
        for (int i = 0; i < lst.size(); i++) {
            System.out.print(lst.get(i));
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            String s = sc.nextLine();
            solve(s);
        }
    }
}
