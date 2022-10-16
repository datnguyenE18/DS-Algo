import java.util.Scanner;

public class Main {
    static int cnt = 0;

    public static void BT(int bac, int buoc, int remain) {
        if (remain <= 0) {
            cnt++;
            return;
        }
        for (int i = 1; i <= buoc; i++) {
            if (i <= remain) {
                BT(bac, buoc, remain - i);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();
        for (int tc = 0; tc < t; tc++) {
            cnt = 0;
            int bac = sc.nextInt();
            int buoc = sc.nextInt();
            BT(bac, buoc, bac);
            System.out.println(cnt);
        }
    }

}
