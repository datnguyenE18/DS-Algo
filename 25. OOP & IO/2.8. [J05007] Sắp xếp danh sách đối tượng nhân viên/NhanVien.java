import java.text.*;
import java.util.*;

public class NhanVien implements Comparable<NhanVien> {
    private String ma, ten, gioiTinh, diaChi, maSoThue;
    private Date ns, hopDong;

    public NhanVien(int ma, String ten, String gioiTinh, String ns, String diaChi, String maSoThue, String hopDong)
            throws ParseException {
        this.ma = String.format("%05d", ma);
        this.ten = ten;
        this.gioiTinh = gioiTinh;
        this.ns = new SimpleDateFormat("dd/mm/yyyy").parse(ns);
        this.diaChi = diaChi;
        this.maSoThue = maSoThue;
        this.hopDong = new SimpleDateFormat("dd/mm/yyyy").parse(hopDong);
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + gioiTinh + " " + new SimpleDateFormat("dd/mm/yyyy").format(ns) + " " + diaChi
                + " " + maSoThue + " " + new SimpleDateFormat("dd/mm/yyyy").format(hopDong);
    }

    @Override
    public int compareTo(NhanVien o) {
        if (ns.getTime() > o.ns.getTime()) {
            return 1;
        }
        if (ns.getTime() < o.ns.getTime()) {
            return -1;
        }
        return 0;
    }

}
