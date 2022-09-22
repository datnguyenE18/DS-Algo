import java.util.Scanner;

public class JvPrj {

    private static void bubble_Sort(int arr[], int n) {
        int step = 1; // số bước

        for (int i = n - 1; i > 0; i--) {
            // Kiểm tra xem arr có thay đổi không:
            boolean isChange = false;

            // Nếu 2 số đối nghịch thì đổi chỗ
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[j + 1]) {
                    isChange = true;
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }

            // Nếu thay đổi thì in ra arr ở bước này:
            if (isChange) {
                System.out.print("Buoc " + step + ": ");
                for (int j = 0; j < n; j++) {
                    System.out.print(arr[j] + " ");
                }
                System.out.println();
                step++;
            }
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
        bubble_Sort(arr, n);
    }
}
