package Solution;

import java.util.*;

public class Bai02 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Nhập chiều cao: ");
        int height = in.nextInt();
        for(int i = 1; i <= height; i++){
            for(int j = 1; j <= height - i; j++)
                System.out.print(" ");
            for(int j = 1; j <= i; j++)
                System.out.print(j);
            for(int j = i - 1; j >= 1; j--)
                System.out.print(j);
            System.out.println();
        }
    }
}
