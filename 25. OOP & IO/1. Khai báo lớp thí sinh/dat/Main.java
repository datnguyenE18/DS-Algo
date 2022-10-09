import java.text.ParseException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws ParseException {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        String birth = sc.nextLine();
        double diem1 = sc.nextDouble(),
                diem2 = sc.nextDouble(),
                diem3 = sc.nextDouble();

        ThiSinh thiSinh = new ThiSinh(name, birth, diem1, diem2, diem3);
        System.out.println(thiSinh);
    }
}