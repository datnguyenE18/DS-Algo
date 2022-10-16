import java.text.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws ParseException {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        List<NhanVien> ds = new ArrayList<>();
        for (int i = 1; i <= t; i++) {
            ds.add(new NhanVien(i, sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(),
                    sc.nextLine()));
        }
        Collections.sort(ds);
        for (NhanVien nv : ds) {
            System.out.println(nv);
        }
    }
}
