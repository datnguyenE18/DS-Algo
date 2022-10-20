public class SinhVien implements Comparable<SinhVien> {
    private String name;
    private float score;
    private String code = "SV", type;

    public SinhVien(String name, float lt, float th, float test, int code) {
        this.name = standard(name);
        this.code += String.format("%02d", code);
        this.score = (float) (lt * 0.25 + th * 0.35 + test * 0.4);
        this.type = typeDefine(this.score);
    }

    private static String standard(String name) {
        name = name.replaceAll("\\s+", " ").trim().toLowerCase();

        String[] tmp = name.split(" ");
        String res = "";

        for (int i = 0; i < tmp.length; i++) {
            res += Character.toString(tmp[i].charAt(0)).toUpperCase();
            res += tmp[i].substring(1);
            if (i < tmp.length)
                res += " ";
        }
        return res;
    }

    private static String typeDefine(float score) {
        if (score >= 8.0) {
            return "GIOI";
        } else if (score >= 6.5 && score < 8) {
            return "KHA";
        } else if (score < 5) {
            return "KEM";
        }
        return "TRUNG BINH";
    }

    @Override
    public String toString() {
        return this.code + " " + this.name + " " + String.format("%.2f", this.score) + " " + this.type;
    }

    @Override
    public int compareTo(SinhVien o) {
        if (this.score > o.score)
            return -1;
        if (this.score < o.score)
            return 1;
        return 0;
    }

}