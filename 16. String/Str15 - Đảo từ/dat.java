import java.util.Scanner;

public class test {

    public static void reverseWordInMyString(String str) {
        String[] words = str.split(" ");
        String res = "";
        for (String i : words) {
            StringBuilder tmp = new StringBuilder(i);
            res += tmp.reverse();
            res += " ";
        }

        System.out.println(res);

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            String abc = sc.nextLine();
            reverseWordInMyString(abc);
        }
    }
}