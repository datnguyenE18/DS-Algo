import java.util.Scanner;

public class Main {

    private static void nextBit(String s) {
        StringBuilder bit = new StringBuilder(s);
        for (int i = bit.length() - 1; i >= 0; i--) {
            if (bit.charAt(i) == '1')
                bit.replace(i, i + 1, "0");
            else {
                bit.replace(i, i + 1, "1");
                break;
            }
        }
        System.out.println(bit);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            String bit = sc.nextLine();
            nextBit(bit);
        }
    }

}

// Thời gian: 0.15s
// Bộ nhớ: 33688Kb