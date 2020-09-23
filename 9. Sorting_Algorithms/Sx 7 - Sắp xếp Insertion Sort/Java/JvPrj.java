package jvprj;

import java.util.*;

public class JvPrj {

    public static void main( String[] args ) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int a[] = new int[n + 2];
        for ( int i = 0; i < n; i++ ) {
            a[i] = scanner.nextInt();
        }
        System.out.print("Buoc 0: " + a[0]);
        System.out.println();
        for ( int i = 1; i < n; i++ ) {
            int value = a[i];
            int j = i - 1;
            while ( j >= 0 && a[j] > value ) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = value;
            System.out.print("Buoc " + i + ": ");
            for ( int k = 0; k <= i; k++ ) {
                System.out.print(a[k] + " ");
            }
            System.out.println();
        }
    }
}
