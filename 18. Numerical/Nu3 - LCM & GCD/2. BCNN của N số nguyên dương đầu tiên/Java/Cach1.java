import java.util.*;

public class Cach1 {

    public static long UCLN( long a, long b ) {
        if ( a == 0 )
            return b;
        else
            return UCLN(b % a, a);
    }

    public static long BCNN( long a, long b ) {
        return ( a * b ) / UCLN(a, b);
    }

    public static void main( String[] args ) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while ( t-- > 0 ) {
            long n = sc.nextLong();
            long BC = 1;
            for ( int i = 1; i <= n; i++ ) {
                BC = BCNN(BC, i);
            }
            System.out.println(BC);
        }
    }
}
