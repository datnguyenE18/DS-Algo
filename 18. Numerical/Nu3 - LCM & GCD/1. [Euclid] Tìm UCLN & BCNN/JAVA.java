import java.util.Scanner;

public class Main {

    private static long UCLN(long a, long b) {
        if (a == 0)
            return b;
        return UCLN(b % a, a);
    }

    private static long BCNN(long a, long b, long ucln) {
        return (a * b) / ucln;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            long a = sc.nextLong(),
                    b = sc.nextLong();
            long ucln = UCLN(a, b);
            System.out.println(BCNN(a, b, ucln) + " " + UCLN(a, b));
        }
    }

}