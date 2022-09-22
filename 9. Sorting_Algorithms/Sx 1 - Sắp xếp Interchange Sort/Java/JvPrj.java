package jvprj;

import java.util.Scanner;

public class JvPrj {
    private static void sort(int arr[], int n) {
        for (int st = 0; st < n - 1; st++) { // Không cần quét số cuối cùng nữa vì đăng trước đã được sắp xếp rồi
            for (int run = st + 1; run < n; run++) {
                if (arr[st] > arr[run]) {
                    int temp = arr[st];
                    arr[st] = arr[run];
                    arr[run] = temp;

                }

            }
            System.out.print("Buoc " + (st + 1) + ": ");
            for (int i = 0; i < n; i++)
                System.out.print(arr[i] + " ");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(),
                arr[] = new int[n];

        // Nhập các phần tử array:
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        // Sắp xếp:
        sort(arr, n);
    }
}
