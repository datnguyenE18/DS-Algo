package Solution;

import java.util.*;

public class Bai03 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Nhập số trong khoảng 10..99: ");
        int numNeedsFound = in.nextInt();
        Random rand = new Random(); //Lớp Random trong java.util
        int count = 1;
        while(true){
            int randomNum = rand.nextInt(99 - 10) + 10;  //Sinh số ngẫu nhiên trong khoảng         
            System.out.println("Lần " + count + ": Sinh ngẫu nhiên số " + randomNum);
            if(randomNum == numNeedsFound){
                System.out.println(randomNum + " là số cần tìm, kết thúc sau " + count + " lần tìm kiếm !");
                break;
            }
            else{
                System.out.println(randomNum + " không phải số cần tìm, tiếp tục !");
                count++; //Tăng biến đếm thêm 1
                continue;
            }
        }
    }
}