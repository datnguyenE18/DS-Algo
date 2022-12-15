public class Gamer implements Comparable<Gamer> {
    private String ma, ten;
    private int vao, ra, tgian;

    public Gamer(String ma, String ten, String vao, String ra) {
        this.ma = ma;
        this.ten = ten;
        this.vao = Integer.parseInt(vao.substring(0, 2)) * 60 + Integer.parseInt(vao.substring(3));
        this.ra = Integer.parseInt(ra.substring(0, 2)) * 60 + Integer.parseInt(ra.substring(3));
        this.tgian = this.ra - this.vao;
    }

    private String time() {
        String gio = String.valueOf(tgian / 60);
        String phut = String.valueOf(tgian % 60);
        return gio + " gio " + phut + " phut";
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + time();
    }

    @Override
    public int compareTo(Gamer o) {
        if (tgian < o.tgian) {
            return 1;
        }
        if (tgian > o.tgian) {
            return -1;
        }
        return 0;
    }
}
