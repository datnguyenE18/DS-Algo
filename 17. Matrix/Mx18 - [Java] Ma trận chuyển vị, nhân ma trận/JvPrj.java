package jvprj;

import java.util.*;

public class JvPrj {

    public static void main( String[] args ) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for ( int k = 1; k <= t; k++ ) {
            int m = in.nextInt();
            int n = in.nextInt();
            int a[][] = new int[m + 2][n + 2];
            int b[][] = new int[n + 2][m + 2];

            // Nhập ma trận:
            for ( int i = 1; i <= m; i++ )
                for ( int j = 1; j <= n; j++ )
                    a[i][j] = in.nextInt();

            // Xác định ma trận chuyển vị
            for ( int i = 1; i <= m; i++ )
                for ( int j = 1; j <= n; j++ )
                    b[j][i] = a[i][j];

            // Thực hiện phép nhân
            int res[][] = new int[m + 2][m + 2]; // Ma trận kết quả
            for ( int i = 1; i <= m; i++ )
                for ( int j = 1; j <= m; j++ ) {
                    res[i][j] = 0;
                    for ( int r = 1; r <= n; r++ )
                        res[i][j] += ( a[i][r] * b[r][j] );
                }

            // In ra kết quả:
            System.out.println("Test " + k + ":");
            for ( int i = 1; i <= m; i++ ) {
                for ( int j = 1; j <= m; j++ )
                    System.out.print(res[i][j] + " ");
                System.out.println();
            }
        }
    }
}
