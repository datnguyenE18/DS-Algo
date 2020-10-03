package jvprj;

import java.util.*;

public class JvPrj {

    public static void main( String[] args ) {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextInt();

        while ( t-- > 0 ) {
            long n = sc.nextLong();
            solve(n);
        }
    }

    private static void solve( long n ) {
        long res = 0;
        while ( n % 2 == 0 ) {
            res = 2;
            n /= 2;
        }

        for ( long i = 3; i <= Math.sqrt(n); i += 2 )
            while ( n % i == 0 ) {
                n /= i;
                res = i;
            }

        if ( n > 2 )
            res = n;
        System.out.println(res);
    }
}
