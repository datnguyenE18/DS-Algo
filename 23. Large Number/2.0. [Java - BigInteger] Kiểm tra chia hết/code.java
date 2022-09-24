import java.math.BigInteger;
import java.util.Scanner;

public class App {

    private static void checkDiv(BigInteger a, BigInteger b) {
        if (a.compareTo(b) > 0) { // Nếu a > b
            BigInteger tmp = a.divide(b); // Thì lấy a / b
            if (a.compareTo(b.multiply(tmp)) == 0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        } else { // Nếu a <= b
            BigInteger tmp = b.divide(a);
            if (b.compareTo(a.multiply(tmp)) == 0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();

            checkDiv(a, b);
        }
    }
}