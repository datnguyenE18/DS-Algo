import java.util.Scanner;

public class App {

    public static void standardise(String a, int o) {
        a = a.trim();
        a = a.replaceAll("\\s+", " ");
        String tmp[] = a.split(" ");
        String res = "";

        if (o == 1) {
            res += String.valueOf(tmp[tmp.length - 1].charAt(0)).toUpperCase();
            res += tmp[tmp.length - 1].substring(1).toLowerCase();
            res += " ";

            for (int i = 0; i < tmp.length - 1; i++) {
                res += String.valueOf(tmp[i].charAt(0)).toUpperCase();
                res += tmp[i].substring(1).toLowerCase();
                if (i < tmp.length - 1)
                    res += " ";
            }
        } else {
            for (int i = 1; i < tmp.length; i++) {
                res += String.valueOf(tmp[i].charAt(0)).toUpperCase();
                res += tmp[i].substring(1).toLowerCase();
                if (i < tmp.length - 1)
                    res += " ";
            }
            res += " ";
            res += String.valueOf(tmp[0].charAt(0)).toUpperCase();
            res += tmp[0].substring(1).toLowerCase();
        }

        System.out.println(res);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int option = sc.nextInt();
            sc.nextLine();
            String name = sc.nextLine();
            standardise(name, option);
        }
    }
}
