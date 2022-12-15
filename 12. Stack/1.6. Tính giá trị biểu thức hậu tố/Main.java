
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String s = sc.nextLine();
            System.out.println(tinhGiaTri(s));
        }
    }

    public static long tinhGiaTri(String str) {
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < str.length(); i++) {
            char tmp = str.charAt(i);
            if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/' || tmp == '^' || tmp == '%') {
                int pop1 = stack.pop(), pop2 = stack.pop();
                int temp = 0;
                switch (tmp) {
                    case '+':
                        stack.push(pop2 + pop1);
                        break;
                    case '-':
                        stack.push(pop2 - pop1);
                        break;
                    case '*':
                        stack.push(pop2 * pop1);
                        break;
                    case '/':
                        stack.push(pop2 / pop1);
                        break;
                    case '^':
                        stack.push((int) Math.pow(pop2, pop1));
                        break;
                    case '%':
                        stack.push(pop2 % pop1);
                        break;
                    default:
                        stack.push(0);
                }
            } else {
                stack.push(Character.getNumericValue(tmp));
            }
        }
        return stack.peek();
    }
}

// 231*+9- --> 2 3 1 --> 2 (3 + 1) --> 2 4 --> (2 + 4) --> 6 --> 6 9 --> (6 - 9) --> -4
