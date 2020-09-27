package jvprj;

import java.math.BigInteger;
import java.util.*;

public class JvPrj {

    private static int Mod( BigInteger n ) {
        if ( n.mod(BigInteger.valueOf(4)) == BigInteger.ZERO )
            return 4;
        return 0;
    }

    public static void main( String[] args ) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while ( t-- > 0 ) {
            BigInteger n = scanner.nextBigInteger();
            System.out.println(Mod(n));
        }
    }
}
