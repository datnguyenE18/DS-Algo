import java.text.ParseException;
import java.util.Scanner;

public class Main {
    private static long UCLN(long ts, long ms) {
        if (ts == 0)
            return ms;
        return UCLN(ms % ts, ts);
    }

    public static void main(String[] args) throws ParseException {
        Scanner sc = new Scanner(System.in);
        long ts = sc.nextLong();
        long ms = sc.nextLong();
        long ucln = UCLN(ts, ms);
        PhanSo res = new PhanSo(ts / ucln, ms / ucln);
        System.out.println(res);
    }

}