import java.util.Scanner;

public class Main {

    private static void Next_Bits_String(String s) {
        StringBuilder bit = new StringBuilder(s);
        int i = bit.length() - 1;

        for (; i >= 0 && bit.charAt(i) == '1'; i--) {
            bit.replace(i, i + 1, "0");
        }
        if (i >= 0)
            bit.replace(i, i + 1, "1");
        System.out.println(bit);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            String s = sc.nextLine();
            Next_Bits_String(s);
        }
    }

}

// Thời gian: 0.17s
// Bộ nhớ: 33076Kb