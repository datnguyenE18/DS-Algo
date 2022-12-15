import java.io.*;
import java.util.*;
import java.util.ArrayList;

public class Main {
    public static float diemKhuvuc(String s) {
        String sub = s.substring(0, 3);
        if (sub.equals("KV1"))
            return (float) 0.5;
        if (sub.equals("KV2"))
            return (float) 1.0;
        return (float) 2.5;
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("THISINH.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<ThiSinh> arrL = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine();
            String hoten = sc.nextLine();
            float math = Float.parseFloat(sc.nextLine());
            float phy = Float.parseFloat(sc.nextLine());
            float chemis = Float.parseFloat(sc.nextLine());
            float kv = diemKhuvuc(ma);
            ThiSinh ts = new ThiSinh(ma, hoten, math, phy, chemis, kv);
            arrL.add(ts);
        }
        Collections.sort(arrL, new TDComparator());
        int chitieu = Integer.parseInt(sc.nextLine());
        float diem = arrL.get(chitieu - 1).getTongdiem();
        System.out.println(diem);
        for (ThiSinh x : arrL) {
            if (x.getTongdiem() >= diem) {
                System.out.println(x + "TRUNG TUYEN");
            } else {
                System.out.println(x + "TRUOT");
            }
        }
    }
}