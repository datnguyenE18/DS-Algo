import java.util.Scanner;
import java.util.TreeSet;

public class Point {

    public static void solve(TreeSet<Integer> A, TreeSet<Integer> B) {
        TreeSet<Integer> giao = new TreeSet<>();
        giao.addAll(A);

        A.removeAll(B);
        giao.removeAll(A);

        for (Integer i : giao)
            System.out.print(i + " ");
        
            System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Khai báo
        int n = sc.nextInt();
        int m = sc.nextInt();
        TreeSet<Integer> A = new TreeSet<>();
        TreeSet<Integer> B = new TreeSet<>();

        // Nhập chuỗi A:
        for (int i = 0; i < n; i++)
            A.add(sc.nextInt());

        // Nhập cuỗi B:
        for (int i = 0; i < m; i++)
            B.add(sc.nextInt());

        solve(A, B);
    }
}