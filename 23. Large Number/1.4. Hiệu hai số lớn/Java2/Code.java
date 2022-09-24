import java.math.BigInteger;
import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger A = sc.nextBigInteger();
        BigInteger B = sc.nextBigInteger();

        BigInteger res = A.subtract(B);

        System.out.println(res);

    }
}