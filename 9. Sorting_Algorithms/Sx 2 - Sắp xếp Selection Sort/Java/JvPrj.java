package jvprj;

import java.util.Scanner;

public class JvPrj {

    private static void selection_Sort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            int min = arr[i],
                    vt_min = i;

            for (int j = i; j < n; j++) {
                if (arr[j] < min) {
                    min = arr[j];
                    vt_min = j;
                }
            }

            // Hoán đổi a[vt_min] và a[i]
            int tmp = min;
            arr[vt_min] = arr[i];
            arr[i] = tmp;

            System.out.print("Buoc " + (i + 1) + ": ");
            for (int k = 0; k < n; k++) {
                System.out.print(arr[k] + " ");
            }
            System.out.println();
        }
    }
    
    public static void main( String[] args ) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];

        // Nhập các phần tử array:
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        // Sắp xếp:
        selection_Sort(arr, n);
    }
}
