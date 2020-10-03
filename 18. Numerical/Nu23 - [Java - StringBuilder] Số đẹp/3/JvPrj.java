package jvprj;

import java.util.*;

public class JvPrj {

    public static void main( String[] args ) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while ( t-- > 0 ) {
            String a = sc.next();
            if ( check(a) )
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }

    private static boolean check( String a ) {
        for ( int i = 0; i < a.length(); i++ )
            if ( !isPrime(a.charAt(i)) )
                return false;
        String tmp = new StringBuilder(a).reverse().toString();
        if ( a.compareTo(tmp) == 0 )
            return true;
        return false;
    }

    private static boolean isPrime( char c ) {
        return ( c == '2' || c == '3' || c == '5' || c == '7' );
    }
}
