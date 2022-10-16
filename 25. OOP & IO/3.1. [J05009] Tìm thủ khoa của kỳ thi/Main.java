import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        List<SinhVien> ds = new ArrayList<>();
        for (int i = 1; i <= t; i++) {
            ds.add(new SinhVien(i, sc.nextLine(), sc.nextLine(), Float.parseFloat(sc.nextLine()),
                    Float.parseFloat(sc.nextLine()), Float.parseFloat(sc.nextLine())));
        }
        Collections.sort(ds);
        System.out.println(ds.get(0));
        for (int i = 1; i < t; i++) {
            if (ds.get(i).getTong() < ds.get(i - 1).getTong()) {
                break;
            }
            System.out.println(ds.get(i));
        }
    }
}
