package jvprj;

import java.util.*;

public class JvPrj {

    public static void main( String[] args ) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int dem = 0;
        int a[] = new int[n + 2];
        for ( int i = 0; i < n; i++ ) {
            a[i] = scanner.nextInt();
        }
        for ( int i = 0; i < n; i++ ) {
            boolean is_sorted = true;
            for ( int j = 1; j < n - i; j++ ) {
                if ( a[j - 1] > a[j] ) {
                    int tmp = a[j - 1];
                    a[j - 1] = a[j];
                    a[j] = tmp;
                    is_sorted = false;
                }
            }
            if ( is_sorted ) {
                break;
            }

            System.out.print("Buoc " + ( i + 1 ) + ": ");
            for ( int k = 0; k < n; k++ ) {
                System.out.print(a[k] + " ");
            }
            System.out.println();

        }
    }
}
