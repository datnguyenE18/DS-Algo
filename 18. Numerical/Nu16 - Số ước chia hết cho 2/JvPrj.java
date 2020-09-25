package jvprj;

import java.util.*;

public class JvPrj {

    private static long countEvenDivisors( long n ) {
        long count = 1;
        if ( n % 2 != 0 ) {
            return 0;
        } else {
            n /= 2;
            for ( long i = 2; i <= Math.sqrt(n); i++ ) {
                int counti = 0;
                while ( n % i == 0 ) {
                    n /= i;
                    counti++;
                }
                if ( counti > 0 ) {
                    count *= ( counti + 1 );
                }
            }
        }
        if ( n > 1 ) {
            count *= 2;
        }
        return count;
    }

    public static void main( String[] args ) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while ( t-- > 0 ) {
            long a = in.nextLong();
            System.out.println(countEvenDivisors(a));
        }

    }
}
