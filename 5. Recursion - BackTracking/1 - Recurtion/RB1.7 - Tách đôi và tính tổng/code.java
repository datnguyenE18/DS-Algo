import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    private static void tongDoi(String num) {

        if (num.length() == 1) {
            return;
        } else {
            String a = num.substring(0, num.length() / 2);
            String b = num.substring(num.length() / 2);

            BigInteger s1 = new BigInteger(a);
            BigInteger s2 = new BigInteger(b);
            BigInteger tmp = s1.add(s2);

            String res = tmp.toString();
            System.out.println(res);
            tongDoi(res);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String num = sc.nextLine();
        tongDoi(num);
    }

}