
import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);
    static int res[] = new int[15];
    static int vs[] = new int[15];

    public static void main(String[] args) {
        int tc;
        tc = sc.nextInt();
        for (int m = 0; m < tc; m++) {
            int t;
            t = sc.nextInt();
            for (int i = 0; i <= t; i++) {
                vs[i] = -1;
                res[i] = -1;
            }
            BT(t, 1);
        }
    }

    public static void BT(int k, int step) {
        if (step > k) {
            for (int i = 1; i <= k; i++) {
                System.out.print(res[i]);
            }
            System.out.print("\n");
            return;
        }
        for (int i = k; i >= 1; i--) {
            if (vs[i] == -1 && i != res[step - 1] + 1 && i != res[step - 1] - 1) {
                vs[i] = 1;
                res[step] = i;
                BT(k, step + 1);
                vs[i] = -1;
                res[step] = -1;
            }
        }
    }
}
