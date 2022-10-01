import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws ParseException {
        Scanner sc = new Scanner(System.in);
        String code = "B20DCCN001";
        String name = sc.nextLine();
        String lop = sc.nextLine();
        String birth = sc.nextLine();
        float gpa = sc.nextFloat();

        Date ngaysinh = new SimpleDateFormat("dd/MM/yyyy").parse(birth);

        System.out.println(code + " " + name + " " + lop + " " + new SimpleDateFormat("dd/MM/yyyy").format(ngaysinh)
                + " " + String.format("%.2f", gpa));
    }
}