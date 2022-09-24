import java.util.Scanner;

public class App {

    private static boolean checkArr(int arr[], int n) {
        int j = n - 1;
        for (int i = 0; i < n; i++) {
            for (; j >= 0;) {
                if (arr[i] != arr[j]) {
                    return false;
                } else if (j <= i) {
                    return true;
                } else {
                    j--;
                    break;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];

            // Nhập mảng:
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            // solve:
            if (checkArr(arr, n)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
