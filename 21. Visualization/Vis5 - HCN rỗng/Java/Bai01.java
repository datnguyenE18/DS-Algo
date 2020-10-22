package Solution;

import java.util.*;

public class Bai01 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Nhập chiều cao hình chữ nhật: ");
        int height = in.nextInt();
        System.out.println("Nhập chiều rộng hình chữ nhật: ");
        int width = in.nextInt();
        for(int i = 1; i <= height; i++){
            for(int j = 1; j <= width; j++){
                if(i == 1 || j == 1 || i == height || j == width)
                    System.out.print("*");
                else
                    System.out.print(" ");
            }
            System.out.println();
        }
    }
}
