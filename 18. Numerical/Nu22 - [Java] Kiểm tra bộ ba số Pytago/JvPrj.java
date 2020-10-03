package jvprj;

import java.util.*;

public class JvPrj {

    private static boolean check( long[] a, int n ) {

        for ( int i = 0; i < n - 1; i++ )
            for ( int j = i + 1; j < n; j++ )
                if ( a[j] < a[i] ) {
                    long tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }

        for ( int i = n - 1; i >= 2; i-- ) {
            int l = 0;
            int r = i - 1;
            while ( l < r ) {
                if ( a[l] + a[r] == a[i] )
                    return true;
                if ( a[l] + a[r] < a[i] )
                    l++;
                else
                    r--;
            }
        }
        return false;
    }

    public static void main( String[] args ) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while ( t-- > 0 ) {
            int n = scanner.nextInt();
            long a[] = new long[n + 2];

            for ( int i = 0; i < n; i++ ) {
                a[i] = scanner.nextInt();
                a[i] = a[i] * a[i];
            }
            if ( check(a, n) )
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
