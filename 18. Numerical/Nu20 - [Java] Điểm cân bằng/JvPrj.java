package jvprj;

import java.util.*;

public class JvPrj {

    static int findElement( int a[], int n ) {
        int sumArray = 0;
        int currentSum = 0;
        for ( int i = 0; i < n; i++ )
            sumArray += a[i];
        for ( int i = 0; i < n; i++ ) {
            if ( currentSum == sumArray - currentSum - a[i] )
                return ( i + 1 );
            currentSum += a[i];
        }
        return -1;
    }

    public static void main( String[] args ) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while ( t-- > 0 ) {
            int n = scanner.nextInt();
            int a[] = new int[n + 1];
            for ( int i = 0; i < n; i++ )
                a[i] = scanner.nextInt();
            System.out.println(findElement(a, n));
        }
    }
}
