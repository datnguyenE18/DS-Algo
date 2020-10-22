package Solution;

import java.util.*;
import java.lang.Math;

public class Bai04 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Nhập n: ");
        long n = in.nextLong();
        double S = 0;
        if((n & 1) == 1){ //so sánh bit phải cùng bằng 1 (hay) n là số lẻ
            S = Math.pow((n + 1) / 2, 2);
        }
        else{ // n chẵn
            n /= 2;
            S = n * (n + 1);
        }
        System.out.println(String.format("%.0f", S));
    }
}