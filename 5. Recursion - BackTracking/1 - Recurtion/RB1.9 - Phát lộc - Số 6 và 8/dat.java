import java.util.Scanner;

public class Main {
    static int res[] = new int[105];
    static Scanner sc = new Scanner(System.in);

    public static void BT(int step, int k, int remain) {
        if (step >= k) {
            if (res[step - 1] == 6) {
                for (int i = 0; i < k; i++) {
                    System.out.print(res[i]);
                }
                System.out.print("\n");
            }
            return;
        }
        if (remain > 0) {
            for (int i = 0; i < 2; i++) {
                if (i == 0) {
                    res[step] = 6;
                    BT(step + 1, k, remain - 1);
                } else if (i == 1 && res[step - 1] != 8) {
                    res[step] = 8;
                    BT(step + 1, k, 3);
                }
            }
        } else {
            res[step] = 8;
            BT(step + 1, k, 3);
        }
    }

    public static void main(String[] args) {
        int t;
        t = sc.nextInt();
        res[0] = 8;
        BT(1, t, 3);
    }

}
