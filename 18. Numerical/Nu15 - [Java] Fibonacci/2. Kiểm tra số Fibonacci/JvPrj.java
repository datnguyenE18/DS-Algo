package jvprj;

import java.util.*;

public class JvPrj {

    public static void main( String[] args ) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while ( t-- > 0 ) {
            long n = sc.nextLong();
            if ( n == 0 || n == 1 || isFibo(n) )
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }

    private static boolean isFibo( long n ) {
        long f1 = 0;
        long f2 = 1;
        long f3 = 1;
        while ( f3 < n ) {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
            if ( f3 == n )
                return true;
        }
        return false;
    }
}
