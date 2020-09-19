import java.util.Scanner;

public class JvPrj {

    public static void main( String[] args ) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while ( t-- > 0 ) {
            int n = sc.nextInt();
            boolean mark = true;
            for ( int i = 2; i < n; i++ ) {
                if ( n % i == 0 ) {
                    mark = false;
                    break;
                }
            }
            if ( mark && n > 1 ) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
