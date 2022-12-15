public class ThiSinh {
    private String ma, hoten;
    private float toan,ly,hoa;

    public ThiSinh() {
    }

    public ThiSinh(String ma, String hoten, float toan, float ly, float hoa) {
        this.ma = ma;
        this.hoten = hoten;
        this.toan = toan;
        this.ly = ly;
        this.hoa = hoa;
    }

    @Override
    public String toString() {
        float tong = tong();
        float diemUT = diemUuTien(ma);
        String s = "TRUNG TUYEN";
        if(tong+diemUT<24) s = "TRUOT";
        //if(diemUT*2 % 2 == 0) return ma + " " + hoten + " " + "1" + " " + tong + " " + s;
        return ma + " " + hoten + " " + Float.valueOf(diemUT).toString().replaceAll("\\.?0*$", "") + 
                " " + Float.valueOf(tong).toString().replaceAll("\\.?0*$", "") + " " + s;
    }

    private float diemUuTien(String ma) {
        char x = ma.charAt(2);
        if(x=='1') return (float) 0.5;
        else if(x=='2') return 1;
        return (float) 2.5;
    }

    private float tong() {
        return toan*2 + ly + hoa;
    }  
}
