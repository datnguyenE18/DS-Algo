package Solution;

import java.util.*;

public class Bai08 {
    public static long sumOfDigits(long n){ //Tìm UCLN dựa vào giải thuật Euclid
        long S = 0L;
        while(n > 0){
            long tmp = n % 10;
            S += tmp;
            n /= 10;
        }
        return S;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Nhập n: ");
        long n = in.nextLong();
        System.out.println(sumOfDigits(n));
    }
}