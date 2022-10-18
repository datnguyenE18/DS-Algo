import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.text.*;

public class Main {
    public static void main(String[] args) throws ParseException, FileNotFoundException {
        Scanner in = new Scanner(new File("SINHVIEN.in"));
        ArrayList<SinhVien> ds = new ArrayList<>();

        int n = Integer.parseInt(in.nextLine());
        for (int i = 1; i <= n; i++) {
            SinhVien tmp = new SinhVien(i, in.nextLine(), in.nextLine(), in.nextLine(),
                    Float.parseFloat(in.nextLine()));
            ds.add(tmp);
        }
        // Collections.sort(ds);
        for (SinhVien tmp : ds) {
            System.out.println(tmp);
        }
    }

}
