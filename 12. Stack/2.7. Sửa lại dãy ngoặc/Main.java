
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String s = sc.next();
            Result(s);
        }
    }

    public static void Result(String s) {
        Scanner sc = new Scanner(s);
        int dem = 0;
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                dem++;
            } else {
                if (dem == 0) {
                    res++;
                    dem++;
                } else {
                    dem--;
                }
            }
        }
        res += dem / 2;
        System.out.println(res);
    }

}
