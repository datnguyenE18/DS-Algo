import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    private static BigInteger UCLN(BigInteger a, BigInteger b) {
        if (a.equals(BigInteger.ZERO))
            return b;
        return UCLN(b.mod(a), a);
    }

    private static BigInteger BCNN(BigInteger a, BigInteger b) {
        return (a.multiply(b)).divide(UCLN(a, b));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            BigInteger a = sc.nextBigInteger(),
                    b = sc.nextBigInteger();
            System.out.println(BCNN(a, b));
        }
    }
}