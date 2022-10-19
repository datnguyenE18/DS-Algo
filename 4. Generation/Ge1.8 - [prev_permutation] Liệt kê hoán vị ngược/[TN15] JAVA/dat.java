import java.util.Scanner;

public class Main {
    static int vs[] = new int[15];
    static int res[] = new int[15];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();
        for (int tc = 0; tc < t; tc++) {
            int n;
            n = sc.nextInt();
            BT(n, 0);
            System.out.print("\n");
        }
    }

    public static void BT(int k, int cnt) {
        if (cnt >= k) {
            for (int i = 0; i < cnt; i++) {
                System.out.print(res[i]);
            }
            System.out.print(" ");
            return;
        }
        for (int i = k; i >= 1; i--) {
            if (vs[i] == 0) {
                vs[i] = 1;
                res[cnt] = i;
                BT(k, cnt + 1);
                vs[i] = 0;
            }
        }
    }
}