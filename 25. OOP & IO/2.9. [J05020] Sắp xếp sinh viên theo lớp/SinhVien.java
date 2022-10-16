public class SinhVien implements Comparable<SinhVien> {
    private String ma, ten, lop, email;

    public SinhVien(String ma, String ten, String lop, String email) {
        this.ma = ma;
        this.ten = ten;
        this.lop = lop;
        this.email = email;
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + lop + " " + email;
    }

    @Override
    public int compareTo(SinhVien o) {
        if (lop.equals(o.lop)) {
            return ma.compareTo(o.ma);
        }
        return lop.compareTo(o.lop);
    }
}
