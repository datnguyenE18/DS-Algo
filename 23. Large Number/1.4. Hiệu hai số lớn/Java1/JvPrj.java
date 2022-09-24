package jvprj;

import java.math.BigInteger;
import java.util.*;

public class JvPrj {

    private static int getDigitCount( BigInteger number ) {
        double factor = Math.log(2) / Math.log(10);
        int digitCount = (int) ( factor * number.bitLength() + 1 );
        if ( BigInteger.TEN.pow(digitCount - 1).compareTo(number) > 0 )
            return digitCount - 1;
        return digitCount;
    }

    public static void main( String[] args ) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        scanner.nextLine();
        while ( t-- > 0 ) {
            BigInteger a = scanner.nextBigInteger();
            BigInteger b = scanner.nextBigInteger();
            for ( int i = 1; i <= getDigitCount(a.max(b)) - getDigitCount(a.subtract(b).abs()); i++ )
                System.out.print("0");
            System.out.print(a.subtract(b).abs());
            System.out.println();
        }
    }
}
