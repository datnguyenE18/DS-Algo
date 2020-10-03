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
        if ( a.charAt(0) != '8' || a.charAt(a.length() - 1) != '8' )
            return false;
        StringBuilder tmp = new StringBuilder();
        int sum = 0;
        for ( int i = 0; i < a.length(); i++ ) {
            tmp.append(a.charAt(i) - '0').toString();
            sum += a.charAt(i) - '0';
        }
        if ( sum % 10 != 0 )
            return false;
        if ( a.compareTo(tmp.toString()) == 0 )
            return true;
        return false;
    }
}
