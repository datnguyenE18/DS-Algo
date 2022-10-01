import java.util.Scanner;

public class Point {

    private static boolean checkThuanNghich(String s) {
        StringBuilder sb = new StringBuilder(s);
        if (s.equals(sb.toString()))
            return true;
        return false;
    }

    private static boolean checkChan(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (Character.getNumericValue(s.charAt(i)) % 2 != 0) {
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
            String s = sc.nextLine();

            if (checkChan(s) && checkThuanNghich(s)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

}