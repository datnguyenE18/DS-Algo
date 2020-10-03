package jvprj;

import java.util.*;

public class JvPrj {

    static int Largestpower( int n, int p ) {
        int ans = 0;
        while ( n > 0 ) {
            n /= p;
            ans += n;
        }
        return ans;
    }

    public static void main( String[] args ) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while ( t-- > 0 ) {
            int n = scanner.nextInt();
            int p = scanner.nextInt();
            System.out.println(Largestpower(n, p));
        }
    }
}
