import java.util.Scanner;

public class App {
    static long[] f = new long[93];

    private static void fibo() {
        f[1] = 1;
        f[2] = 1;

        for (int i = 3; i <= 92; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
    }

    public static void main(String[] agrs) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        fibo();
        while (t-- > 0) {
            int n = sc.nextInt();
            System.out.println(f[n]);
        }
    }
}