import java.util.*;

public class JvPrj {

    // Finding Fibonacci:
    public static long fibo( long n ) {
        long res = 3,
                F1 = 1,
                F2 = 1;
        if ( n == 1 || n == 2 ) {
            return 1;
        }
        for ( long i = 3; i <= n; i++ ) {
            res = F1 + F2;
            F1 = F2;
            F2 = res;
        }
        return res;
    }

    // Main:
    public static void main( String[] args ) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while ( t-- > 0 ) {
            long n = sc.nextInt();
            System.out.println(fibo(n));
        }
    }
}
