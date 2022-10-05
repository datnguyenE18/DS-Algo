import java.util.Arrays;
import java.util.Scanner;

public class Rectange {

    public static int[] swap(int data[], int left, int right) {
        int temp = data[left];
        data[left] = data[right];
        data[right] = temp;
        return data;
    }

    public static int[] reverse(int data[], int left, int right) {
        while (left < right) {
            int temp = data[left];
            data[left++] = data[right];
            data[right--] = temp;
        }
        return data;
    }

    public static boolean findNextPermutation(int data[]) {

        if (data.length <= 1)
            return false;
        int last = data.length - 2;

        while (last >= 0) {
            if (data[last] < data[last + 1])
                break;
            last--;
        }

        if (last < 0)
            return false;

        int nextGreater = data.length - 1;

        for (int i = data.length - 1; i > last; i--) {
            if (data[i] > data[last]) {
                nextGreater = i;
                break;
            }
        }

        data = swap(data, nextGreater, last);
        data = reverse(data, last + 1, data.length - 1);
        return true;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[] data = new int[n];

            for (int i = 0; i < data.length; i++) {
                data[i] = sc.nextInt();
            }

            if (!findNextPermutation(data)) {
                Arrays.sort(data);
                for (int i : data)
                    System.out.print(i + " ");
                System.out.println();
            } else {
                for (int i : data)
                    System.out.print(i + " ");
                System.out.println();
            }
        }

    }
}

// Thời gian: 0.16
// Bộ nhớ: 41352Kb