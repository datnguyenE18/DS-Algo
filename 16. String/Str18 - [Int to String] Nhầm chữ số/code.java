import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();

        String A = Integer.toString(a);
        String B = Integer.toString(b);

        int min = Integer.parseInt(A.replace('6', '5')) + Integer.parseInt(B.replace('6', '5'));
        int max = Integer.parseInt(A.replace('5', '6')) + Integer.parseInt(B.replace('5', '6'));

        System.out.println(min + " " + max);
    }
}
