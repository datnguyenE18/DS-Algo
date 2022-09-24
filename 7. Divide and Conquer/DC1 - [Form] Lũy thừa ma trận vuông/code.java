import java.util.Scanner;

public class test {

    static long mod = 1000000007;

    public static long[][] nhanMaTran(long[][] arr, long[][] arr2, int n) {
        long[][] res = new long[n + 5][n + 5];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    res[i][j] += arr[i][k] * arr2[k][j];
                    res[i][j] %= mod;
                }
            }
        }
        return res;
    }

    public static long[][] CDT(long[][] arr, int n, int k) {
        if (k == 1)
            return arr;
        long[][] tmp = CDT(arr, n, k / 2);
        if (k % 2 == 0)
            return nhanMaTran(tmp, tmp, n);
        return nhanMaTran(nhanMaTran(tmp, tmp, n), arr, n);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt();
            int k = in.nextInt();
            long[][] arr = new long[n + 5][n + 5];
            long[][] res = new long[n + 5][n + 5];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    arr[i][j] = in.nextInt();
            }
            res = CDT(arr, n, k);
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < n; j++) {
            //         System.out.print(res[i][j] + " ");
            //     }
            //     System.out.println();
            // }
            long ans = 0;
            for (int i = 0; i < n; i++)
                ans = (ans + res[i][n - 1]) % mod;
            System.out.println(ans);
        }
    }
}