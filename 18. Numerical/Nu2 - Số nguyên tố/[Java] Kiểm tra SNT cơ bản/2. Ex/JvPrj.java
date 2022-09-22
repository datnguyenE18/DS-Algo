import java.util.Scanner;

public class JvPrj {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            boolean isSNT = true;
            int X = sc.nextInt();

            // Check SNT:
            if (X <= 0) {
                isSNT = false;
            } else if (X != 0) {
                for (int i = 2; i < X; i++) {
                    if (X % i == 0) {
                        isSNT = false;
                        break;
                    }
                }
            }

            // In ra kết quả:
            if (isSNT) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
