package jvprj;

import java.util.*;

public class JvPrj {

    private static long countPairs( long a[], int n, long sum ) {
        HashMap<Long, Integer> hm = new HashMap<>();
        for ( int i = 0; i < n; i++ ) {
            if ( !hm.containsKey(a[i]) )
                hm.put(a[i], 0);
            hm.put(a[i], hm.get(a[i]) + 1);
        }

        long count = 0;
        for ( int i = 0; i < n; i++ ) {
            if ( hm.get(sum - a[i]) != null ) //Tìm thấy phần tử cộng thành sum
                count += hm.get(sum - a[i]);
            if ( a[i] + a[i] == sum )
                count--;
        }
        return count / 2; //Do mỗi cặp được đếm 2 lần
    }

    public static void main( String[] args ) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while ( t-- > 0 ) {
            int n = scanner.nextInt();
            long sum = scanner.nextInt();
            long a[] = new long[n + 2];
            for ( int i = 0; i < n; i++ )
                a[i] = scanner.nextInt();
            System.out.println(countPairs(a, n, sum));
        }
    }
}
