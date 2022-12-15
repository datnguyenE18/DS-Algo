import java.util.Scanner;

public class Main {
    static int vs[] = new int[105];
    static int n, k, s;
    static int cnt;
    static Scanner sc = new Scanner(System.in);

    public static void BT(int limit, int tong, int curr) {
        if (limit >= k) {
            if (tong == s)
                cnt++;
            return;
        }
        if (tong > s) {
            return;
        }
        if (curr > n)
            return;
        for (int i = 1; i <= 2; i++) {
            if (i == 1) {
                BT(limit + 1, tong + curr, curr + 1);
            } else {
                BT(limit, tong, curr + 1);
            }
        }
    }

    public static void main(String[] args) {
        while (true) {
            n = sc.nextInt();
            k = sc.nextInt();
            s = sc.nextInt();
            if (n == 0 && k == 0 && s == 0) {
                break;
            } else {
                cnt = 0;
                BT(0, 0, 1);
                System.out.println(cnt);
            }
        }
    }

}
