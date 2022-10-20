import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        List<SinhVien> ds = new ArrayList<>();
        for (int i = 1; i <= t; i++) {
            ds.add(new SinhVien(i, sc.nextLine(),
                    Float.parseFloat(sc.next()), Float.parseFloat(sc.next()), Float.parseFloat(sc.next()),
                    Float.parseFloat(sc.next()), Float.parseFloat(sc.next()), Float.parseFloat(sc.next()),
                    Float.parseFloat(sc.next()), Float.parseFloat(sc.next()), Float.parseFloat(sc.next()),
                    Float.parseFloat(sc.next())));
            sc.nextLine();
        }
        Collections.sort(ds);
        for (SinhVien sv : ds) {
            System.out.println(sv);
        }
    }
}
