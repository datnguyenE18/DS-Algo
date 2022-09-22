import java.util.Scanner;

public class JvPrj {

    private static void insertion_Sort(int arr[], int n) {
        // quét từng giá trị 1:
        for (int i = 0; i < n; i++) {
            // tìm vị trí thích hợp:
            for (int j = 0; j <= i; j++) { // Quét từ đầu tới vị trí i đó
                
                // Nếu nhỏ hơn số nào là vị trí ở đó luôn:
                if (arr[i] < arr[j]) {
                    int save = arr[i], pos = j; // Lưu giá trị và vị trí của arr[i]
                    
                    // Dịch dần sang phải để chỗ lại cho arr[i]:
                    for (int k = i - 1; k >= pos; k--)
                        arr[k + 1] = arr[k];
                    
                    // Để arr[i] lại vị trí đã chọn:
                    arr[pos] = save;
                }
            }

            System.out.print("Buoc " + i + ": ");
            for (int k = 0; k <= i; k++) {
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
        insertion_Sort(arr, n);
    }
}
