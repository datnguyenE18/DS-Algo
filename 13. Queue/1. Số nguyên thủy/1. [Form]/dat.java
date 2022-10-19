import java.util.Scanner;

public class Main {
    static int res[] = new int[20];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();
        for (int tc = 0; tc < t; tc++) {
            int num;
            num = sc.nextInt();
            int cnt = 0;
            for (int i = 1; i <= num; i++) {
                cnt = (int) (cnt + pow(2, i));
            }
            System.out.print(cnt + "\n");
            for (int i = num; i > 0; i--) {
                BT(i, 0);
            }
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
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                res[cnt] = 8;
                BT(k, cnt + 1);
            } else {
                res[cnt] = 6;
                BT(k, cnt + 1);
            }
        }
    }

    public static int pow(int a, int b) {
        int result = 1;
        for (int i = 1; i <= b; i++) {
            result *= a;
        }
        return result;
    }

}
