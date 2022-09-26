import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;

public class App {

    public static void countDigit(String S) {
        TreeSet<Character> res = new TreeSet<>();

        for (int i = 0; i < S.length(); i++) {
            res.add(S.charAt(i));
        }

        System.out.println(res.size());
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine();

        countDigit(S);
    }
}
