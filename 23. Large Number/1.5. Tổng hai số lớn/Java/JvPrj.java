package jvprj;

import java.math.BigInteger;
import java.util.*;

public class JvPrj {

    public static void main( String[] args ) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        scanner.nextLine();
        while ( t-- > 0 ) {
            BigInteger a = scanner.nextBigInteger();
            BigInteger b = scanner.nextBigInteger();
            System.out.println(a.add(b));
        }
    }
}
