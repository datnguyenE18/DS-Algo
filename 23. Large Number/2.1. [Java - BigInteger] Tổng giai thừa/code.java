import java.math.BigInteger;
import java.util.Scanner;

public class App {

    // Tính giai thừa:
    public static BigInteger giaithua(int n) {
        // Khởi tạo res = 1;
        BigInteger res = BigInteger.ONE;

        for (int i = 1; i <= n; i++)
            res = res.multiply(BigInteger.valueOf(i));

        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        if (n == 0) {
            System.out.print(1);
        } else {
            // Khởi tạo res = 0;
            BigInteger res = BigInteger.ZERO;

            for (int i = 1; i <= n; i++)
                res = res.add(giaithua(i));
            
            System.out.println(res);
        }
    }
}