
public class NhanVien {

    private String manv = "NV01";
    private String hoten;
    private int luongcb;
    private int ngaycong;
    private String chucvu;

    public NhanVien() {
    }

    public NhanVien(String hoten, int luongcb, int ngaycong, String chucvu) {
        this.manv = manv;
        this.hoten = hoten;
        this.luongcb = luongcb;
        this.ngaycong = ngaycong;
        this.chucvu = chucvu;
    }

    @Override
    public String toString() {
        int luong = luongcb * ngaycong;
        int thuong = thuong(ngaycong);
        int phucap = phucap(chucvu);

        return manv + " " + hoten + " " + luong + " " + thuong + " " + phucap + " " + (luong + thuong + phucap);
    }

    private int thuong(int ngaycong) {
        if (ngaycong >= 25) {
            return (int) (0.2 * luongcb * ngaycong);
        } else if (ngaycong < 22) {
            return 0;
        } else {
            return (int) (0.1 * luongcb * ngaycong);
        }
    }

    private int phucap(String chucvu) {
        switch (chucvu) {
            case "GD":
                return 250000;
            case "PGD":
                return 200000;
            case "TP":
                return 180000;
        }
        return 150000;
    }
}
