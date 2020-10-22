package Solution;

import java.util.*;

public class Bai13 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Nhập c: ");
        double c = in.nextDouble();
        double n = 0d;
        while(c * (2 * n + 1) <= 1)
            n++;
        System.out.println(n);
        double pi = 0d;
        for(double i = 0; i <= n; i++){
            pi += Math.pow(-1, i) * (1 / (2 * i + 1));
        }            
        pi *= 4;
        System.out.println(pi);
    }
}