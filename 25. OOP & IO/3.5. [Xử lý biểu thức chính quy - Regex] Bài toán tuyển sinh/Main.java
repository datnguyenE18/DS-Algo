import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ThiSinh ts = new ThiSinh(sc.nextLine(), sc.nextLine(), Float.parseFloat(sc.nextLine()),
                Float.parseFloat(sc.nextLine()), Float.parseFloat(sc.nextLine()));
        System.out.println(ts);
    }
}
