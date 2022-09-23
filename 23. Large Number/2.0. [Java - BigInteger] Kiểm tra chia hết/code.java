import java.math.BigInteger;
import java.util.Scanner;

public class App {

    public static void checkDiv(BigInteger a, BigInteger b) {
        if (a.compareTo(b) > 0) { // Nếu a > b
            BigInteger div = a.divide(b);
            BigInteger again = div.multiply(b);
            if (a.compareTo(again) > 0) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        } else { // nếu a <= b
            BigInteger div = b.divide(a);
            BigInteger again = div.multiply(a);
            if (b.compareTo(again) > 0) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
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