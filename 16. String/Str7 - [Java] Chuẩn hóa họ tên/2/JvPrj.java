package jvprj;

import java.util.*;

public class JvPrj {

    public static void main( String[] args ) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while ( t-- > 0 ) {
            String a = sc.nextLine();
            a = a.trim();
            a = a.replaceAll("\\s+", " ");
            String tmp[] = a.split(" ");
            String res = "";
            for ( int i = 1; i < tmp.length; i++ ) {
                res += String.valueOf(tmp[i].charAt(0)).toUpperCase();
                res += tmp[i].substring(1).toLowerCase();
                if ( i < tmp.length - 1 )
                    res += " ";
            }
            res += ", " + tmp[0].toUpperCase();

            System.out.println(res);
        }
    }
}
