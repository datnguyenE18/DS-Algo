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
        for ( int i = 0; i < a.length(); i++ ) {
            int tmp = a.charAt(i) - '0';
            if ( tmp % 2 != 0 )
                return false;
        }

        String b = new StringBuilder(a).reverse().toString();
        if ( a.compareTo(b) == 0 )
            return true;
        return false;
    }
}
