import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    private static void next_combin(int n, int k, int[] aft) {
        int i = k;
        while (i >= 1 && aft[i] == n - k + i)
            i--;

        if (i > 0) {
            aft[i]++;
            for (int j = i + 1; j <= k; j++)
                aft[j] = aft[i] + j - i;
        }
    }

    private static void result(int k, int[] aft, Set<Integer> bef) {
        int dem = 0;
        for (int i = 1; i <= k; i++) {
            if (!bef.contains(aft[i]))
                dem++;
        }
        if (dem != 0)
            System.out.println(dem);
        else
            System.out.println(k);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            Set<Integer> bef = new HashSet<>();
            int[] aft = new int[100];

            for (int i = 1; i <= k; i++) {
                aft[i] = sc.nextInt();
                bef.add(aft[i]);
            }

            next_combin(n, k, aft);

            result(k, aft, bef);
        }
    }

}
