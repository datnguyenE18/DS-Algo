import java.io.File;
import java.io.IOException;
import java.text.ParseException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws ParseException, IOException {
        Scanner sc = new Scanner(new File("DATA.in"));
        int[] lst = new int[100001];
        Arrays.fill(lst, 0);

        while (sc.hasNext()) {
            int tmp = sc.nextInt();
            lst[tmp]++;
        }

        for (int i = 0; i < 100001; i++) {
            if (lst[i] != 0) {
                System.out.println(i + " " + lst[i]);
            }
        }
    }
}
