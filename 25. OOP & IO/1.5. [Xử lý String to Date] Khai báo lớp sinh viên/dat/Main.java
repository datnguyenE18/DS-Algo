import java.text.ParseException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws ParseException {
        Scanner sc = new Scanner(System.in);

        SinhVien sv = new SinhVien(sc.nextLine(), // name
                sc.nextLine(), // clas
                sc.nextLine(), // birth
                sc.nextFloat()); // gpa

        System.out.println(sv);
    }
}