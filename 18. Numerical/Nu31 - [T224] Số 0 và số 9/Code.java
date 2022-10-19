import java.util.Scanner;

public class Main {
    static int res[] = new int[500];
    static int num[] = new int[500];
    static int n;
    static int minstep = 400;

    public static void BT(int du, int step) {

        if (du == 0) {
            if (step < minstep) {
                minstep = step;
                for (int i = 0; i < step; i++) {
                    num[i] = res[i];
                }
            }

            return;
        }
        if (step > minstep)
            return;
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                res[step] = 0;

                BT((du * 10) % n, step + 1);
            } else {
                res[step] = 9;

                BT(((du * 10) + 9) % n, step + 1);
            }

        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            n = sc.nextInt();
            res[0] = 9;
            int du = 9 % n;

            minstep = 400;
            BT(du, 1);
            for (int i = 0; i < minstep; i++) {
                System.out.print(num[i]);
            }
            System.out.print("\n");
        }
    }

}
