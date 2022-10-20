import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("BANGDIEM.in"));
        ArrayList<SinhVien> ds = new ArrayList<>();
        int t = Integer.parseInt(sc.nextLine());

        for (int i = 1; i <= t; i++) {
            SinhVien tmp = new SinhVien(sc.nextLine(), // name
                    Float.parseFloat(sc.nextLine()), // lt
                    Float.parseFloat(sc.nextLine()), // th
                    Float.parseFloat(sc.nextLine()), // thi
                    i); // số thứ tự

            ds.add(tmp);
        }
        Collections.sort(ds);
        for (SinhVien sv : ds) {
            System.out.println(sv);
        }
    }
}