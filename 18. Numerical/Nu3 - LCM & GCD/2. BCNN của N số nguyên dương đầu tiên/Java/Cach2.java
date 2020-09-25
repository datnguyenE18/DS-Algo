import java.math.BigInteger;
import java.util.*;

public class Cach2 {

    private static BigInteger gcd( BigInteger a, BigInteger b ) {
        return a.gcd(b);
    }

    private static BigInteger lcm( BigInteger a, BigInteger b ) {
        return a.multiply(b).divide(gcd(a, b));
    }

    public static void main( String[] args ) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while ( t-- > 0 ) {
            int n = in.nextInt();
            BigInteger res = BigInteger.ONE;
            for ( int i = 1; i <= n; i++ ) {
                res = lcm(res, BigInteger.valueOf(i));
            }
            System.out.println(res);
        }
    }
}
