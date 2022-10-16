
import java.text.*;
import java.util.*;

public class ThiSinh {
    private String maTS, hoten;
    private float math, phy, chemis, khuvuc;
    private float tongdiem;

    public ThiSinh(String maTS, String hoten, float math, float phy, float chemis, float khuvuc) {
        this.maTS = maTS;
        this.hoten = hoten;
        this.math = math;
        this.phy = phy;
        this.chemis = chemis;
        this.khuvuc = khuvuc;
        this.tongdiem = 2 * math + phy + chemis + khuvuc;
    }

    public float getTongdiem() {
        return tongdiem;
    }

    public String getMaTS() {
        return maTS;
    }

    @Override
    public String toString() {
        DecimalFormat format = new DecimalFormat("0.#");
        String kv = format.format(khuvuc);
        String tong = format.format(tongdiem);
        return maTS + " " + chuanHoa(hoten) + " " + kv + " " + tong + " ";
    }

    private String chuanHoa(String s) {
        StringBuilder kq = new StringBuilder();
        StringTokenizer st = new StringTokenizer(s);
        while (st.hasMoreTokens()) {
            String t = st.nextToken();
            kq.append(Character.toUpperCase(t.charAt(0)));
            for (int i = 1; i < t.length(); i++) {
                kq.append(Character.toLowerCase(t.charAt(i)));
            }
            kq.append(" ");
        }
        return kq.toString().trim();
    }

}
