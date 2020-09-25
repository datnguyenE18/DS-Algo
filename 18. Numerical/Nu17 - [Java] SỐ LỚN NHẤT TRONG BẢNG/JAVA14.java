import java.util.*;

public class JAVA14 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long minR = Integer.MAX_VALUE;
        long minC = Integer.MAX_VALUE;
        long res = 0;
        while(n-- > 0){
            long a = scanner.nextLong();
            long b = scanner.nextLong();
            if(a < minR) 
                minR = a;
            if(b < minC)
                minC = b;
        }
        res = minR * minC;
        System.out.println(res);
    }
}
