package jvprj;

import java.util.*;

public class JvPrj {

    public static void main( String[] args ) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        scanner.nextLine();

        while ( t-- > 0 ) {
            String a = scanner.nextLine();
            a = a.trim();
            a = a.replaceAll("\\s+", " ");
            String tmp[] = a.split(" ");
            String res = "";
            for ( int i = 0; i < tmp.length; i++ ) {
                res += String.valueOf(tmp[i].charAt(0)).toUpperCase();
                res += tmp[i].toLowerCase().substring(1);
                if ( i != tmp.length - 1 )
                    res += " ";
            }
            System.out.println(res);
        }
    }
}
