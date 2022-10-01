public class ThiSinh {
    private String name;
    private String birth;
    private double diem1, diem2, diem3;

    public ThiSinh() {
    }

    public ThiSinh(String name, String birth, double diem1, double diem2, double diem3) {
        this.name = name;
        this.birth = birth;
        this.diem1 = diem1;
        this.diem2 = diem2;
        this.diem3 = diem3;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getBirth() {
        return birth;
    }

    public void setBirth(String birth) {
        this.birth = birth;
    }

    public double getDiem1() {
        return diem1;
    }

    public void setDiem1(double diem1) {
        this.diem1 = diem1;
    }

    public double getDiem2() {
        return diem2;
    }

    public void setDiem2(double diem2) {
        this.diem2 = diem2;
    }

    public double getDiem3() {
        return diem3;
    }

    public void setDiem3(double diem3) {
        this.diem3 = diem3;
    }

    @Override
    public String toString() {
        return name + " " + birth + " " + String.format("%.1f", (diem1 + diem2 + diem3));
    }

}