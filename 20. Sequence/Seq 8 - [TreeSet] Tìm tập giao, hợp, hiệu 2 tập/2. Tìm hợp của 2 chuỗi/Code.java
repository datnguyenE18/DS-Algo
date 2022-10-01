import java.util.Scanner;
import java.util.TreeSet;

public class Point {

    public static void solve(TreeSet<Integer> A, TreeSet<Integer> B) {
        A.removeAll(B);
        A.addAll(B);
        for (Integer i : A)
            System.out.print(i + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        TreeSet<Integer> A = new TreeSet<>();
        TreeSet<Integer> B = new TreeSet<>();

        for (int i = 0; i < n; i++)
            A.add(sc.nextInt());

        for (int i = 0; i < m; i++)
            B.add(sc.nextInt());

        solve(A, B);
    }
}