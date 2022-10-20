import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("BANGDIEM.in"));
        int t = Integer.parseInt(sc.nextLine());
        List<SinhVien> ds = new ArrayList<SinhVien>();
        for (int i = 1; i <= t; i++) {
            ds.add(new SinhVien(i, sc.nextLine(), Float.parseFloat(sc.nextLine()), Float.parseFloat(sc.nextLine()),
                    Float.parseFloat(sc.nextLine())));
        }

        Collections.sort(ds, new MaComparator());
        int xh = 1;
        ds.get(0).setXepHang(1);
        for (int i = 1; i < t; i++) {
            if (Float.parseFloat(ds.get(i).getTb()) < Float.parseFloat(ds.get(i - 1).getTb())) {
                xh = i + 1;
            }
            ds.get(i).setXepHang(xh);
        }
        for (SinhVien sv : ds) {
            System.out.println(sv);
        }
    }
}
