import java.util.Scanner;
import java.util.TreeSet;

public class App {

    public static void solve(TreeSet<Integer> A, TreeSet<Integer> B) {
        TreeSet<Integer> giao = new TreeSet<>();

        // Tìm tập giao
        for (int i : A)
            for (int j : B)
                if (i == j)
                    giao.add(i);

        // In ra tập giao
        for (int i : giao) {
            System.out.print(i + " ");
            A.remove(i);
            B.remove(i);
        }
        System.out.println();

        // In ra tập A-B:
        for (int i : A)
            System.out.print(i + " ");
        System.out.println();

        // In ra tập B-A:
        for (int i : B)
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
