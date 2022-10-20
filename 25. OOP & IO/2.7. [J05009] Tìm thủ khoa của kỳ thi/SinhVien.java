public class SinhVien implements Comparable<SinhVien> {
    private int ma;
    private String ten, ns;
    private float tong;

    public SinhVien(int ma, String ten, String ns, float d1, float d2, float d3) {
        this.ma = ma;
        this.ten = ten;
        this.ns = ns;
        this.tong = d1 + d2 + d3;
    }

    public float getTong() {
        return tong;
    }

    @Override
    public int compareTo(SinhVien o) {
        if (tong < o.tong)
            return 1;
        if (tong > o.tong)
            return -1;
        return 0;
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + ns + " " + tong;
    }
}
