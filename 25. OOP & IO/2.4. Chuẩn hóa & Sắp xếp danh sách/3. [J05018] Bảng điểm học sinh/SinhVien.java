public class SinhVien implements Comparable<SinhVien> {
    private String ma, ten;
    private float toan, van, anh, ly, hoa, sinh, su, dia, cd, cn;

    public SinhVien(int ma, String ten, float toan, float van, float anh, float ly, float hoa, float sinh, float su,
            float dia, float cd, float cn) {
        this.ma = "HS" + String.format("%02d", ma);
        this.ten = ten;
        this.toan = toan * 2;
        this.van = van * 2;
        this.anh = anh;
        this.ly = ly;
        this.hoa = hoa;
        this.sinh = sinh;
        this.su = su;
        this.dia = dia;
        this.cd = cd;
        this.cn = cn;
    }

    private float diemTB() {
        float diemTb = (toan + van + anh + ly + hoa + sinh + su + dia + cd + cn) / 12;
        return (float) (Math.round(diemTb * 10) / 10.0);
    }

    private String xepLoai() {
        if (diemTB() >= 9)
            return "XUAT SAC";
        if (diemTB() >= 8 && diemTB() < 9)
            return "GIOI";
        if (diemTB() >= 7 && diemTB() < 8)
            return "KHA";
        if (diemTB() >= 5 && diemTB() < 7)
            return "TB";
        return "YEU";
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + String.format("%.1f", diemTB()) + " " + xepLoai();
    }

    @Override
    public int compareTo(SinhVien o) {
        if (diemTB() < o.diemTB())
            return 1;
        if (diemTB() > o.diemTB())
            return -1;
        if (diemTB() == o.diemTB()) {
            return ma.compareTo(o.ma);
        }
        return 0;
    }
}
