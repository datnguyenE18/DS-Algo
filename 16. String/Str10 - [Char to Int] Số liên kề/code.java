import java.util.Scanner;

public class App {

    private static boolean checkNum(String N) {
        for (int i = 0; i < N.length() - 1; i++) {
            int s1 = Character.getNumericValue(N.charAt(i));
            int s2 = Character.getNumericValue(N.charAt(i + 1));
            if (Math.abs(s2 - s1) != 1) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            String N = sc.nextLine();

            if (checkNum(N)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
