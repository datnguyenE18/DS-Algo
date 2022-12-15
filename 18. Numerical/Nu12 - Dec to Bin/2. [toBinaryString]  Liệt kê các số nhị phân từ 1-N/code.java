import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n;
            n = sc.nextInt();
            for (int i = 1; i <= n; i++) {
                System.out.print(Integer.toBinaryString(i) + " ");
            }
            System.out.println("\n");
        }
    }
}
