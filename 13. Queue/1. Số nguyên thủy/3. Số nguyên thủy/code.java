import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static Queue<String> q = new LinkedList<>();
    static ArrayList<String> list = new ArrayList<>();

    public static void init() {
        q.add("4");
        q.add("5");
        int t = 10000;
        while (t-- > 0) {
            String tmp = q.peek();
            q.add(tmp + "4");
            q.add(tmp + "5");
            list.add(q.remove());
        }
    }

    private static void generate(int a) {
        for (int i = 0; i < a; i++) {
            String tmp = list.get(i);
            for (int j = 0; j < tmp.length(); j++)
                System.out.print(tmp.charAt(j));
            for (int j = tmp.length() - 1; j >= 0; j--)
                System.out.print(tmp.charAt(j));
            System.out.print(" ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        init();

        while (t-- > 0) {
            int a = sc.nextInt();
            generate(a);
        }
    }

}