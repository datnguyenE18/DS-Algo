import java.util.*;

public class JvPrj {

    public static void solve( long n ) {
        for ( int i = 2; i <= Math.sqrt(n); i++ ) {
            int count = 0;
            while ( n % i == 0 ) {
                n /= i;
                count++;
            }
            if ( count != 0 ) {
                System.out.print(i + "(" + count + ") ");
            }
        }
        if ( n > 2 ) {
            System.out.println(n + "(1)");
        } else System.out.print("\n");
    }

    public static void main( String[] args ) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(), i = 1;
        while ( t-- > 0 ) {
            long n = sc.nextLong();
            System.out.print("Test " + i + ": ");
            solve(n);
            i++;
        }
    }
}
