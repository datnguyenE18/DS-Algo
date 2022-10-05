import java.util.Scanner;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        TreeSet<Character> res = new TreeSet<>();
        for (int i = 0; i < s.length(); i++)
            res.add(s.charAt(i));
        System.out.println(res.size());
    }
}