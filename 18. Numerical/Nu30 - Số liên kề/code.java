import java.util.Scanner;

public class test {

    public static boolean check(long n) {
        int k = 0;
        int t = (int) (n % 10);
        int m = 0;
        n /= 10;
        while (n > 10) {
            k = (int) (n % 10);
            m = t - k;
            t = k;
            n /= 10;
            if (Math.abs(m) != 1)
                return false;
        }
        if (Math.abs(t - n) != 1)
            return false;
        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();
        while (t-- > 0) {
            long n = in.nextLong();

            if (check(n))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
