package jvprj;

import java.util.*;

public class JvPrj {

    public static void main( String[] args ) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while ( t-- > 0 ) {
            String s = sc.nextLine();
            String[] Arr = s.split("");
            Arrays.sort(Arr);
            int sum = 0;
            for ( int i = 0; i < Arr.length; i++ ) {
                int tmp = Arr[i].charAt(0) - '0';
                if ( ( tmp >= 17 && tmp <= 42 ) || ( tmp >= 49 && tmp <= 74 ) )
                    System.out.print(Arr[i]);
                else
                    sum += Integer.parseInt(Arr[i]);
            }
            System.out.println(sum);
        }
    }
}
