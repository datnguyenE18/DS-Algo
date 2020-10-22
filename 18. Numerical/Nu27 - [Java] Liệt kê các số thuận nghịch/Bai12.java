package Solution;

import java.util.*;

public class Bai12 {
    public static void main(String[] args) {
        //Ý tưởng: hai vòng for, 1 vòng in từ 100 đến 999, 1 vòng for viết thuận nghịch lại vòng trên
        for(int i = 100; i <= 999; i++){
            System.out.print(i);
            String r = new StringBuilder(Integer.toString(i)).reverse().toString();
            System.out.print(r + "\n");
        }
    }
}