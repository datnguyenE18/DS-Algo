import java.util.Arrays;
import java.util.Scanner;

public class Rectange {

    public static boolean next_permutation(int[] p) {
        for (int a = p.length - 2; a >= 0; --a)
            if (p[a] < p[a + 1])
                for (int b = p.length - 1;; --b)
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        return false;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[] p = new int[n];

            for (int i = 0; i < p.length; i++) {
                p[i] = sc.nextInt();
            }

            if (next_permutation(p)) {
                for (int i : p)
                    System.out.print(i + " ");
                System.out.println();
            } else {
                Arrays.sort(p);
                for (int i : p)
                    System.out.print(i + " ");
                System.out.println();
            }
        }

    }
}

// Thời gian: 0.15
// Bộ nhớ: 40812Kb