package jvprj;

import java.util.*;

public class JvPrj {

    private static long gcd( long a, long b ) { //Tìm UCLN dựa vào giải thuật Euclid
        long tmp;
        while ( b != 0 ) {
            tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    private static long reduceB( long a, String b ) {
        long res = 0;
        for ( int i = 0; i < b.length(); i++ ) {
            res = ( res * 10 + b.charAt(i) - '0' ) % a;
        }
        return res;
    }

    private static long gcdLarge( long a, String b ) {
        long num = reduceB(a, b);
        return gcd(num, a);
    }

    public static void main( String[] args ) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while ( t-- > 0 ) {
            long a = in.nextLong();
            in.nextLine();
            String b = in.nextLine();
            System.out.println(gcdLarge(a, b));
        }

    }
}
