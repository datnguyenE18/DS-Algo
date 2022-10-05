import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        Stack<Character> tmp = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if (tmp.empty()) {
                tmp.push(s.charAt(i));
            } else if (s.charAt(i) == tmp.get(tmp.size() - 1)) {
                tmp.pop();
            } else {
                tmp.push(s.charAt(i));
            }
        }

        if (!tmp.empty()) {
            for (Character i : tmp)
                System.out.print(i);
            System.out.println();
        } else {
            System.out.println("Empty String");
        }

    }
}