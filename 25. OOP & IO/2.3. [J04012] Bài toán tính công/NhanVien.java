public class NhanVien {
    private String ten, chucVu, ma;
    private int cong, ngay, thang, thuong, phuCap, tong;

    public NhanVien(int ma, String ten, int ngay, int cong, String chucVu) {
        this.ma = String.format("NV%02d", ma);
        this.ten = ten;
        this.chucVu = chucVu;
        this.cong = cong;
        this.ngay = ngay;
        this.phuCap = phuCap(chucVu);
        this.thang = cong * ngay;
        this.thuong = thuong();
        this.tong = thang + phuCap + thuong;
    }

    private int phuCap(String s) {
        if (s.equals("GD"))
            return 250000;
        if (s.equals("PGD"))
            return 200000;
        if (s.equals("TP"))
            return 180000;
        return 150000;
    }

    private int thuong() {
        if (cong < 22)
            return 0;
        if (cong < 25)
            return thang / 10;
        return thang / 5;
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + thang + " " + thuong + " " + phuCap + " " + tong;
    }
}
