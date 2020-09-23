package jvprj;

import java.util.Scanner;

public class JvPrj {

    public static void main( String[] args ) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int a[] = new int[n + 2];
        for ( int i = 1; i <= n; i++ ) {
            a[i] = scanner.nextInt();
        }
        for ( int i = 1; i <= n - 1; i++ ) {
            int min = 1000;
            int vt_min = 0;
            for ( int j = i; j <= n; j++ ) {
                if ( a[j] < min ) {
                    min = a[j];
                    vt_min = j;
                }
            }
            int tmp = a[i];
            a[i] = a[vt_min];
            a[vt_min] = tmp;

            System.out.print("Buoc " + i + ": ");
            for ( int k = 1; k <= n; k++ ) {
                System.out.print(a[k] + " ");
            }
            System.out.println();
        }
    }
}
